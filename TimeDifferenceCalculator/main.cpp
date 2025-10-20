#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <windows.h>
#include <iomanip>
#include <locale>
#include <codecvt>

using namespace std;
using namespace chrono;

struct TimeZone {
    string name;
    string displayName;
    long bias; // offset from UTC in minutes
};

int main() {
    vector<TimeZone> zones;
    wstring_convert<codecvt_utf8<wchar_t>> converter;

    // Retrieve time zones from Windows registry
    HKEY hKey;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        WCHAR subKey[256];
        DWORD subKeySize = sizeof(subKey);
        DWORD index = 0;
        while (RegEnumKeyExW(hKey, index, subKey, &subKeySize, NULL, NULL, NULL, NULL) == ERROR_SUCCESS) {
            wstring tzNameW(subKey);
            string tzName = converter.to_bytes(tzNameW);
            HKEY hSubKey;
            if (RegOpenKeyExW(hKey, tzNameW.c_str(), 0, KEY_READ, &hSubKey) == ERROR_SUCCESS) {
                WCHAR display[256] = {0};
                DWORD displaySize = sizeof(display);
                RegQueryValueExW(hSubKey, L"Display", NULL, NULL, (LPBYTE)display, &displaySize);

                LONG bias = 0;
                DWORD biasSize = sizeof(bias);
                RegQueryValueExW(hSubKey, L"Bias", NULL, NULL, (LPBYTE)&bias, &biasSize);

                wstring wdisplay(display);
                string disp = converter.to_bytes(wdisplay);
                zones.push_back({tzName, disp, (long)bias});
                RegCloseKey(hSubKey);
            }
            subKeySize = sizeof(subKey);
            index++;
        }
        RegCloseKey(hKey);
    }

    // Display available time zones
    cout << "Available time zones:" << endl;
    for (size_t i = 0; i < zones.size(); ++i) {
        cout << i + 1 << ". " << zones[i].displayName << endl;
    }

    // Select source time zone
    int source_idx;
    cout << "\nSelect source time zone (enter number): ";
    cin >> source_idx;
    source_idx--;  // Adjust for 0-based index
    if (source_idx < 0 || source_idx >= zones.size()) {
        cout << "Invalid selection." << endl;
        return 1;
    }
    TimeZone source = zones[source_idx];

    // Enter time in 12-hour format
    string time_str;
    cout << "Enter time in 12-hour format (e.g., 3:00 PM): ";
    cin.ignore();  // Ignore newline from previous input
    getline(cin, time_str);

    // Parse the time string
    int hours, minutes;
    char colon, ampm[3];
    stringstream ss(time_str);
    ss >> hours >> colon >> minutes >> ampm;
    if (ss.fail() || colon != ':') {
        cout << "Invalid time format." << endl;
        return 1;
    }

    // Convert to 24-hour format
    if (string(ampm) == "PM" || string(ampm) == "pm") {
        if (hours != 12) hours += 12;
    } else if (string(ampm) == "AM" || string(ampm) == "am") {
        if (hours == 12) hours = 0;
    } else {
        cout << "Invalid AM/PM format." << endl;
        return 1;
    }

    // Select target time zone
    int target_idx;
    cout << "Select target time zone (enter number): ";
    cin >> target_idx;
    target_idx--;  // Adjust for 0-based index
    if (target_idx < 0 || target_idx >= zones.size()) {
        cout << "Invalid selection." << endl;
        return 1;
    }
    TimeZone target = zones[target_idx];

    // Calculate difference in minutes
    long diff_m = source.bias - target.bias;
    int abs_diff_m = abs(diff_m);
    int diff_h = abs_diff_m / 60;
    int diff_min = abs_diff_m % 60;

    // Calculate target time
    auto source_duration = chrono::hours(hours) + chrono::minutes(minutes);
    auto target_duration = source_duration + chrono::minutes(diff_m);

    int target_h = chrono::duration_cast<chrono::hours>(target_duration).count() % 24;
    int target_m = chrono::duration_cast<chrono::minutes>(target_duration % chrono::hours(1)).count();

    // Display results
    cout << "\nFrom " << source.displayName << " to " << target.displayName << " -> Difference: ";
    if (diff_m >= 0) cout << "+";
    else cout << "-";
    cout << diff_h << " hours " << diff_min << " minutes" << endl;

    cout << "Time in " << source.displayName << ": " << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << endl;
    cout << "Time in " << target.displayName << ": " << setfill('0') << setw(2) << target_h << ":" << setfill('0') << setw(2) << target_m << endl;

    return 0;
}