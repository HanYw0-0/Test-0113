#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

char* ByteToString(unsigned char *ch_in, int inlen)
{
    unsigned char buf[100];
    int i;
    char *buf1;
    char *out_buf;
    buf1 = (char*)malloc(inlen * 2 * sizeof(char));
    out_buf = (char*)malloc(inlen * 2 * sizeof(char));
    memset(&out_buf, 0, inlen * 2);
    memset(buf1, 0, inlen * 2);
    memset(buf, 00, 100);

    for (i = 0; i < inlen; i++)
    {
        if ((ch_in[i] / 16 >= 0) && (ch_in[i] / 16 <= 9))
            buf[i * 2] = ch_in[i] / 16 + 0x30;
        else
            buf[i * 2] = ch_in[i] / 16 + 0x57;

        if ((ch_in[i] % 16 >= 0) && (ch_in[i] % 16 <= 9))
            buf[i * 2 + 1] = ch_in[i] % 16 + 0x30;
        else
            buf[i * 2 + 1] = ch_in[i] % 16 + 0x57;
    }
    //memcpy(out_buf, buf, inlen * 2);

    for (i = 0; i < inlen * 2; i++)
    {
        sprintf(buf1, "%c", buf[i]);
        strcat(out_buf, buf1);
    }

    printf("\nout_buf: ");
    for (i = 0; i < inlen * 2; i++)
    {
        printf(" %02x", out_buf[i]);
    }
    printf("\n");
    //free(buf1);
    return out_buf;
}

int main()
{
    int i, b, pointer;
    char bcc[10];
    long temp;
    char Time[]={0x20,0x21,0x01,0x12,0x10,0x30,0x30,0x11,0x22,0x33};
    unsigned char *Bime, *Dime;
    unsigned char inbuf[35], outbuf[35], inlen, outlen;
    unsigned char Cime[20];

    ////temp = toMoto(0x062438);

    //char acc[10] = { 0x62, 0x22, 0x02, 0x10, 0x01, 0x11, 0x81, 0x77, 0x73, 0x9f };

    //bcc[0] = acc[0] >> 4;
    //bcc[1] = (acc[0] << 4) + (acc[1] >> 4);
    //bcc[2] = (acc[1] << 4) + (acc[2] >> 4);
    //bcc[3] = (acc[2] << 4) + (acc[3] >> 4);
    //printf("bcc: %02X %02X %02X %02X\n", bcc[0], bcc[1], bcc[2], bcc[3]);

    //char a[10] = {0x00,0x00,0x00,0x2A};
    //printf("请输入一个16进制的数:\n");
    ////gets_s(a,10);//gets从标准输入设备读字符串函数。可以无限读取，不会判断上限，以回车结束读取
    ////b = func(a);
    //printf("%d\n", func(a));

    //memcpy(Time, "\x20\x20\x12\x23\x10\x30\x30\x10\x30\x10", 10);
    Bime = ByteToString(&Time[0], 10);
    printf("Bime: ");
    for (i = 0; i < 20; i++)
    {
        printf(" %02x", Bime[i]);
    }

    memcpy(Cime, Bime, 20);
    printf("\nCime: ");
    for (i = 0; i < 20; i++)
    {
        printf(" %02x", Cime[i]);
    }
    printf("\n");

    system("pause");

    return 0;
}