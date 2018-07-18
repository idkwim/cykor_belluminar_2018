// get_flag.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


char usage[] = "Usage: get_flag.exe \"<your team id>\"";

int main(int argc, char **argv)
{
	unsigned char keybuf[100] = { 0, };
	if (argc < 2) {
		puts(usage);
		return 0;
	}
	sprintf_s((char *)keybuf, sizeof(keybuf), "hey this is key: %s lol", argv[1]);
	struct AES_ctx ctx;
	char buf[100] = { 0, };
	strcpy_s(buf, sizeof(buf), "this is my secret text!!!!!!!!!!!!!!!");
	AES_init_ctx(&ctx, keybuf);
	AES_ECB_encrypt(&ctx, (uint8_t *)buf);
	printf("flag is FLAG{");
	for (int i = 0; i < 16; i++) {
		printf("%02hhx", buf[i]);
	}
	puts("}");
    return 0;
}

