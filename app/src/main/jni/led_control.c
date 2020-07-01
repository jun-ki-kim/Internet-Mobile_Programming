//
// Created by kimjunki on 2020-05-31.
//

#include "com_example_myapplication_MainActivity.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int LED_ON (int number)
{
    int value = 0;
    int ret;
    int fd_led = -1;
    int bit = 1;
    int i;

    fd_led = open("/dev/fpga_led", O_RDWR);
    if (fd_led == -1) return 0;

    while(bit < 60)
    {
        value = 1 << number;
        ret = write(fd_led, &value, sizeof(value));
        number++;
        usleep(50000);
        if(number == 8)
        {
            for (i = 1; i < 7; ++i)
            {
                value = value >> 1;
                ret = write(fd_led, &value, sizeof(value));
                usleep(50000);
            }
            number = 0;
        }
        bit++;
    }

    value = 0;

    ret = write(fd_led, &value, sizeof(value));
    close(fd_led);
    return ret;
}

int LED_OFF (int number)
{
    short value;
    int ret;
    int fd_led = -1;
    int bit = 1;

    if (number > 9 || number < 1) return 0;
    fd_led = open("/dev/fpga_led", O_RDWR);
    if (fd_led == -1) return 0;
    ret = read(fd_led, &value, sizeof(value));

    bit = 1 << number;
    bit = ~bit;
    value &= bit;

    ret = write(fd_led, &value, sizeof(value));
    close(fd_led);
    return ret;
}

int PIEZO_ON (int number)
{
    int fdev = 0;
    int ret = 0;
    int value = 0;
    int no = 0;

    fdev = open("/dev/fpga_piezo", O_RDWR);

    value = 0x01;
    ret = write(fdev, &value, sizeof(value));
    usleep(150000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(100000);

    value = 0x01;
    ret = write(fdev, &value, sizeof(value));
    usleep(150000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(100000);

    value = 0x05;
    ret = write(fdev, &value, sizeof(value));
    usleep(150000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(100000);

    value = 0x05;
    ret = write(fdev, &value, sizeof(value));
    usleep(150000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(100000);

    value = 0x06;
    ret = write(fdev, &value, sizeof(value));
    usleep(150000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(100000);

    value = 0x06;
    ret = write(fdev, &value, sizeof(value));
    usleep(150000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(100000);

    value = 0x05;
    ret = write(fdev, &value, sizeof(value));
    usleep(300000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(200000);

    value = 0x04;
    ret = write(fdev, &value, sizeof(value));
    usleep(150000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(100000);

    value = 0x04;
    ret = write(fdev, &value, sizeof(value));
    usleep(150000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(100000);

    value = 0x03;
    ret = write(fdev, &value, sizeof(value));
    usleep(150000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(100000);

    value = 0x03;
    ret = write(fdev, &value, sizeof(value));
    usleep(150000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(100000);

    value = 0x02;
    ret = write(fdev, &value, sizeof(value));
    usleep(150000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(100000);

    value = 0x02;
    ret = write(fdev, &value, sizeof(value));
    usleep(150000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(100000);

    value = 0x01;
    ret = write(fdev, &value, sizeof(value));
    usleep(300000);

    value = no;
    ret = write(fdev, &value, sizeof(value));
    usleep(200000);

    close(fdev);

    return 0;
}

int Segment_ON (int number)
{
    int fdev = 0;
    int ret = 0;
    int value = 0;

    fdev = open("/dev/fpga_segment", O_RDWR);

    value = 0x01;
    ret = write(fdev, &value, sizeof(value));
    usleep(3000000);

    value = 0;
    ret = write(fdev, &value, sizeof(value));

    close(fdev);

    return 0;
}

int Fullcolorled_ON (int number)
{
    int fdev = 0;
    int ret = 0;
    int value = 0;

    fdev = open("/dev/fpga_fullcolorled", O_RDWR);

    value = 0x03;
    ret = write(fdev, &value, sizeof(value));
    usleep(500000);

    value = 0x04;
    ret = write(fdev, &value, sizeof(value));
    usleep(500000);

    value = 0x05;
    ret = write(fdev, &value, sizeof(value));
    usleep(500000);

    value = 0;
    ret = write(fdev, &value, sizeof(value));

    close(fdev);

    return 0;
}

JNIEXPORT void JNICALL Java_com_example_myapplication_MainActivity_turnOnLed
(JNIEnv *env, jobject this_ptr)
{
    LED_ON(0);
}

JNIEXPORT void JNICALL Java_com_example_myapplication_MainActivity_turnOffLed
(JNIEnv *env, jobject this_ptr)
{
    LED_OFF(1);
}

JNIEXPORT void JNICALL Java_com_example_myapplication_MainActivity_turnOnPiezo
        (JNIEnv *env, jobject this_ptr)
{
    PIEZO_ON(1);
}

JNIEXPORT void JNICALL Java_com_example_myapplication_MainActivity_turnOnSegment
        (JNIEnv *env, jobject this_ptr)
{
    Segment_ON(1);
}

JNIEXPORT void JNICALL Java_com_example_myapplication_MainActivity_turnOnFullcolorled
        (JNIEnv *env, jobject this_ptr)
{
    Fullcolorled_ON(1);
}