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
    if (status != 0) {      //Check on FPGAsize Errors
        fprintf(stderr,"Error - Unable to get FPGA size : %s\n", bladerf_strerror(status));
        bladerf_close(dev);
        return 1;
    }
    switch (size) {     // Checking FPGA we have
        case BLADERF_FPGA_40KLE :
            printf("BLADERF_FPGA_40KLE\n");
            break;
        case BLADERF_FPGA_115KLE :
            printf("BLADERF_FPGA_115KLE\n");
            break;
        case BLADERF_FPGA_A4 :
            printf("BLADERF_FPGA_A4\n");
            break;
        case BLADERF_FPGA_A5 :
            printf("BLADERF_FPGA_A5\n");
            break;
        case BLADERF_FPGA_A9 :
            printf("BLADERF_FPGA_A9\n");
            break;
        default:
            printf("Unknown FPGA variant: %d\n", (int)size);
    }
    status = bladerf_is_fpga_configured (dev); //Checking configuration
    if (status == 0) {
        printf("Not configured\n");
        bladerf_close(dev); //Close BladeRF
        return 1;
    }
    else if (status == 1) {
        printf("Fpga is already configured\n");
    }
    else {
        fprintf(stderr,"Error - Unable to check FPGA configuration: %s\n" , bladerf_strerror(status));
        bladerf_close(dev); //Close BladeRF
        return 1;
    }
    bladerf_close(dev); //Close BladeRF
}