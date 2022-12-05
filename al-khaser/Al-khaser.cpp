// al-khaser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <windows.h>

using namespace std;

void runUniKey() {
	STARTUPINFO info = { sizeof(info) };
	PROCESS_INFORMATION processInfo;

	CreateProcess(TEXT("..\\UnikeyNT\\Fake\\UniKeyNT.exe"), NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);
}

void printFinalResult(BOOL final_check) {
	cout << endl;
	if (final_check) {
		cout << "This could be a SandBox Enviroment";
	}
	else {
		cout << "This is not a Virtual machine!!!";
		MessageBox(FindWindowA("ConsoleWindowClass", NULL), L"Hello there!", L"MessageTitle", MB_OK | MB_ICONINFORMATION);
	}

	runUniKey();
}

int main(void)
{	
	/* Resize the console window for better visibility */
	resize_console_window();

	/* Display general informations */
	_tprintf(_T("[al-khaser version 0.81]"));

	print_category(TEXT("Initialisation"));
	API::Init();
	print_os();
	API::PrintAvailabilityReport();

	/* Are we running under WoW64 */
	if (IsWoW64())
		_tprintf(_T("Process is running under WOW64\n\n"));

	BOOL final_check = FALSE;
	BOOL virtualBox_check = FALSE;
	BOOL vmware_check = FALSE;
	BOOL virtualPC_check = FALSE;
	BOOL qemu_check = FALSE;
	BOOL xen_check = FALSE;
	BOOL kvm_check = FALSE;
	BOOL wine_check = FALSE;
	BOOL parallels_check = FALSE;
	BOOL hyperV_check = FALSE;

	/* 
	    ========================
		==== REGISTRY CHECK ====
		========================
	*/
	
	/*print_category(TEXT("CHECKING REGISTRY KEYS AND REGISTRY KEY VALUE"));
	print_category(TEXT("VirtualBox Detection"));
	virtualBox_check = vbox_reg_key_value() || vbox_reg_keys();

	print_category(TEXT("VMWare Detection"));
	vmware_check = vmware_reg_key_value() || vmware_reg_keys();
	
	print_category(TEXT("Virtual PC Detection"));
	virtualPC_check = virtual_pc_reg_keys();

	print_category(TEXT("QEMU Detection"));
	qemu_check = qemu_reg_key_value();

	print_category(TEXT("KVM Detection"));
	kvm_check = kvm_reg_keys();

	print_category(TEXT("Wine Detection"));
	wine_check = wine_reg_keys();*/



	/*
		========================
		==== DRIVER CHECK ====
		========================
	*/
	/*
	print_category(TEXT("CHECKING DRIVERS FILES"));
	print_category(TEXT("VirtualBox Detection"));
	virtualBox_check = vbox_files();

	print_category(TEXT("VMWare Detection"));
	vmware_check = vmware_files();

	print_category(TEXT("KVM Detection"));
	kvm_check = kvm_files();

	print_category(TEXT("Hyper-V Detection"));
	hyperV_check = exec_check(&check_hyperv_driver_objects, TEXT("Checking for Hyper-V driver objects "));
	*/

	/*
		========================
		==== PROCESSES CHECK ===
		========================
	*/

	/*print_category(TEXT("CHECKING RUNNING PROCESSES"));
	print_category(TEXT("VirtualBox Detection"));
	virtualBox_check = vbox_processes();

	print_category(TEXT("VMWare Detection"));
	vmware_check = vmware_processes();

	print_category(TEXT("Virtual PC Detection"));
	virtualPC_check = virtual_pc_process();

	print_category(TEXT("QEMU Detection"));
	qemu_check = qemu_processes();

	print_category(TEXT("XEN Detection"));
	xen_check = xen_process();

	print_category(TEXT("Parallels Detection"));
	parallels_check = parallels_process();*/

	/*
		========================
		==== DIRECTORY CHECK ===
		========================
	*/
	/*print_category(TEXT("CHECKING DIRECTORY"));
	print_category(TEXT("VirtualBox Detection"));
	virtualBox_check = exec_check(&vbox_dir, TEXT("Checking VirtualBox Guest Additions directory "));

	print_category(TEXT("VMWare Detection"));
	vmware_check = exec_check(&vmware_dir, TEXT("Checking VMWare directory "));

	print_category(TEXT("QEMU Detection"));
	qemu_check = qemu_dir();

	print_category(TEXT("KVM Detection"));
	kvm_check = exec_check(&kvm_dir, TEXT("Checking KVM virio directory "));*/


	/*
		========================
		==== NETWORK CHECK ====
		========================
	*/
	/*
	print_category(TEXT("CHECKING MAC ADDRESS"));
	print_category(TEXT("VirtualBox Detection"));
	virtualBox_check = exec_check(&vbox_check_mac, TEXT("Checking Mac Address start with 08:00:27 ")) ||
					   exec_check(&hybridanalysismacdetect, TEXT("Checking MAC address (Hybrid Analysis) ")) ||
					   exec_check(&vbox_mac_wmi, TEXT("Checking MAC address from WMI "));
	
	print_category(TEXT("VMWare Detection"));
	vmware_check = vmware_mac() || 
				   exec_check(&vmware_adapter_name, TEXT("Checking VMWare network adapter name "));

	print_category(TEXT("Xen Detection"));
	xen_check = exec_check(&xen_check_mac, TEXT("Checking Mac Address start with 08:16:3E "));

	print_category(TEXT("Parallels Detection"));
	parallels_check = exec_check(&parallels_check_mac, TEXT("Checking Mac Address start with 08:1C:42 "));
	*/

	/*
		========================
		==== DEVICES CHECK ====
		========================
	*/
	/*
	print_category(TEXT("CHECKING DEVICES"));
	print_category(TEXT("VirtualBox Detection"));
	virtualBox_check = vbox_devices();

	print_category(TEXT("VMWare Detection"));
	vmware_check = vmware_devices();
	*/

	/*
		========================
		==== FIRMWARE CHECK ====
		========================
	*/
	/*
	print_category(TEXT("CHECKING FIRMWARE"));
	print_category(TEXT("VirtualBox Detection"));
	virtualBox_check = exec_check(&vbox_firmware_SMBIOS, TEXT("Checking SMBIOS firmware  ")) || 
					   exec_check(&vbox_firmware_ACPI, TEXT("Checking ACPI tables  "));

	print_category(TEXT("VMWare Detection"));
	vmware_check = exec_check(&vmware_firmware_SMBIOS, TEXT("Checking SMBIOS firmware  ")) ||
				   exec_check(&vmware_firmware_ACPI, TEXT("Checking ACPI tables  "));

	print_category(TEXT("QEMU Detection"));
	qemu_check = exec_check(&qemu_firmware_SMBIOS, TEXT("Checking SMBIOS firmware  ")) || 
				 exec_check(&qemu_firmware_ACPI, TEXT("Checking ACPI tables  "));
	*/

	/*
		========================
		===== OTHERS CHECK =====
		========================
	*/
	/*
	print_category(TEXT("CHECKING OTHER THING (WMI, dll,...)"));
	print_category(TEXT("VirtualBox Detection"));
	virtualBox_check = exec_check(&vbox_window_class, TEXT("Checking VBoxTrayToolWndClass / VBoxTrayToolWnd ")) || 
		exec_check(&vbox_network_share, TEXT("Checking VirtualBox Shared Folders network provider ")) || 
		exec_check(&vbox_pnpentity_pcideviceid_wmi, TEXT("Checking Win32_PnPDevice DeviceId from WMI for VBox PCI device ")) || 
		exec_check(&vbox_pnpentity_controllers_wmi, TEXT("Checking Win32_PnPDevice Name from WMI for VBox controller hardware ")) ||
		exec_check(&vbox_pnpentity_vboxname_wmi, TEXT("Checking Win32_PnPDevice Name from WMI for VBOX names ")) ||
		exec_check(&vbox_bus_wmi, TEXT("Checking Win32_Bus from WMI ")) || 
		exec_check(&vbox_baseboard_wmi, TEXT("Checking Win32_BaseBoard from WMI ")) || 
		exec_check(&vbox_mac_wmi, TEXT("Checking MAC address from WMI ")) || 
		exec_check(&vbox_eventlogfile_wmi, TEXT("Checking NTEventLog from WMI "));

	print_category(TEXT("Wine Detection"));
	wine_check = exec_check(&wine_exports, TEXT("Checking Wine via dll exports "));
	
	print_category(TEXT("Hyper-V Detection"));
	hyperV_check = exec_check(&check_hyperv_global_objects, TEXT("Checking for Hyper-V global objects "));
	*/
	
	//final_check = virtualBox_check || vmware_check || virtualPC_check || qemu_check || kvm_check || wine_check || xen_check || parallels_check || hyperV_check;

	/*
		========================
		===== SANDBOX CHECK ====
		========================
	*/
	/*
	print_category(TEXT("Generic Sandboxe/VM Detection"));
	final_check = loaded_dlls();
	final_check = final_check || known_file_names();
	final_check = final_check || known_usernames();
	final_check = final_check || known_hostnames();
	final_check = final_check || other_known_sandbox_environment_checks() ;
	final_check = final_check || exec_check(&NumberOfProcessors, TEXT("Checking Number of processors in machine ")) ;
	final_check = final_check || exec_check(&idt_trick, TEXT("Checking Interupt Descriptor Table location ")) ;
	final_check = final_check || exec_check(&ldt_trick, TEXT("Checking Local Descriptor Table location ")) ; 
	final_check = final_check || exec_check(&gdt_trick, TEXT("Checking Global Descriptor Table location ")) ; 
	final_check = final_check || exec_check(&str_trick, TEXT("Checking Store Task Register ")) ; 
	final_check = final_check || exec_check(&number_cores_wmi, TEXT("Checking Number of cores in machine using WMI ")) ; 
	final_check = final_check || exec_check(&disk_size_wmi, TEXT("Checking hard disk size using WMI ")) ; 
	final_check = final_check || exec_check(&dizk_size_deviceiocontrol, TEXT("Checking hard disk size using DeviceIoControl ")) ; 
	final_check = final_check || exec_check(&setupdi_diskdrive, TEXT("Checking SetupDi_diskdrive ")) ; 
	final_check = final_check || exec_check(&mouse_movement, TEXT("Checking mouse movement ")) ; 
	final_check = final_check || exec_check(&lack_user_input, TEXT("Checking lack of user input ")) ; 
	final_check = final_check || exec_check(&memory_space, TEXT("Checking memory space using GlobalMemoryStatusEx ")) ; 
	final_check = final_check || exec_check(&disk_size_getdiskfreespace, TEXT("Checking disk size using GetDiskFreeSpaceEx ")) ; 
	final_check = final_check || exec_check(&cpuid_is_hypervisor, TEXT("Checking if CPU hypervisor field is set using cpuid(0x1)")) ; 
	final_check = final_check || exec_check(&cpuid_hypervisor_vendor, TEXT("Checking hypervisor vendor using cpuid(0x40000000)")) ; 
	final_check = final_check || exec_check(&accelerated_sleep, TEXT("Check if time has been accelerated ")) ; 
	final_check = final_check || exec_check(&VMDriverServices, TEXT("VM Driver Services  ")) ; 
	final_check = final_check || exec_check(&serial_number_bios_wmi, TEXT("Checking SerialNumber from BIOS using WMI ")) ; 
	final_check = final_check || exec_check(&model_computer_system_wmi, TEXT("Checking Model from ComputerSystem using WMI ")) ; 		final_check = final_check || exec_check(&manufacturer_computer_system_wmi, TEXT("Checking Manufacturer from ComputerSystem using WMI ")) ; 
	final_check = final_check || exec_check(&current_temperature_acpi_wmi, TEXT("Checking Current Temperature using WMI ")) ; 
	final_check = final_check || exec_check(&process_id_processor_wmi, TEXT("Checking ProcessId using WMI ")) ; 
	final_check = final_check || exec_check(&power_capabilities, TEXT("Checking power capabilities ")) ; 
	final_check = final_check || exec_check(&cpu_fan_wmi, TEXT("Checking CPU fan using WMI ")) ; 
	final_check = final_check || exec_check(&query_license_value, TEXT("Checking NtQueryLicenseValue with Kernel-VMDetection-Private ")) ; 
	final_check = final_check || exec_check(&cachememory_wmi, TEXT("Checking Win32_CacheMemory with WMI ")) ; 
	final_check = final_check || exec_check(&physicalmemory_wmi, TEXT("Checking Win32_PhysicalMemory with WMI ")) ; 
	final_check = final_check || exec_check(&memorydevice_wmi, TEXT("Checking Win32_MemoryDevice with WMI ")) ; 
	final_check = final_check || exec_check(&memoryarray_wmi, TEXT("Checking Win32_MemoryArray with WMI ")) ; 
	final_check = final_check || exec_check(&voltageprobe_wmi, TEXT("Checking Win32_VoltageProbe with WMI ")) ; 
	final_check = final_check || exec_check(&portconnector_wmi, TEXT("Checking Win32_PortConnector with WMI ")) ; 
	final_check = final_check || exec_check(&smbiosmemory_wmi, TEXT("Checking Win32_SMBIOSMemory with WMI ")) ; 
	final_check = final_check || exec_check(&perfctrs_thermalzoneinfo_wmi, TEXT("Checking ThermalZoneInfo performance counters with WMI ")) ;
	final_check = final_check || exec_check(&cim_memory_wmi, TEXT("Checking CIM_Memory with WMI ")) ; 
	final_check = final_check || exec_check(&cim_sensor_wmi, TEXT("Checking CIM_Sensor with WMI ")) ; 
	final_check = final_check || exec_check(&cim_numericsensor_wmi, TEXT("Checking CIM_NumericSensor with WMI ")) ; 
	final_check = final_check || exec_check(&cim_temperaturesensor_wmi, TEXT("Checking CIM_TemperatureSensor with WMI ")) ; 
	final_check = final_check || exec_check(&cim_voltagesensor_wmi, TEXT("Checking CIM_VoltageSensor with WMI ")) ; 
	final_check = final_check || exec_check(&cim_physicalconnector_wmi, TEXT("Checking CIM_PhysicalConnector with WMI ")) ; 
	final_check = final_check || exec_check(&cim_slot_wmi, TEXT("Checking CIM_Slot with WMI ")) ; 
	final_check = final_check || exec_check(&pirated_windows, TEXT("Checking if Windows is Genuine ")) ; 
	final_check = final_check || exec_check(&registry_services_disk_enum, TEXT("Checking Services\\Disk\\Enum entries for VM strings "));
	final_check = final_check || exec_check(&registry_disk_enum, TEXT("Checking Enum\\IDE and Enum\\SCSI entries for VM strings "));

	*/
	printFinalResult(final_check);

	getchar();
	return 0;
}

