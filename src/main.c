#include <stdio.h>
#include <libbladeRF.h>

int main (int argc, char *argv[]) {
    struct bladerf *dev = NULL;
    int status = bladerf_open(&dev, NULL);
    bladerf_fpga_size size;
    if (status != 0) {
        fprintf(stderr,"Error - Unable to open BladeRF : %s\n", bladerf_strerror(status));
        return 1;
    }
    printf("bladerf_open status %d\n", status); //Print status of BRF
    status = bladerf_get_fpga_size (dev, &size); // Checking Fpga size
    if (status != 0) {
        fprintf(stderr,"Error - Unable to get FPGA size : %s\n", bladerf_strerror(status));
        bladerf_close(dev);
        return 1;
    }
    printf("FPGA size: %d\n" ,(int)size); //Print FPGA Size
    bladerf_close(dev); //Close BladeRF
}