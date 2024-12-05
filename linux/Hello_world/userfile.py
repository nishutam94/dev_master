def main():
    print("This is basic application to access the /proc/My_first_proc_drver")

    driver_handle =  open("/proc/My_first_proc_driver")
    message = driver_handle.readline()
    print(message)
    driver_handle.close()

    return 0

main()
