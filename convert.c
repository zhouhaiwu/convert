/*
程序的大体思路：定义两个数组(str、str2)，数组str，按照1~numRows进行Z型排序，
然后遍历str数组，按1~numRows顺序把值从s写入到str2中；
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * convert(char * s, int numRows){
    int len = strlen(s);
    int size = sizeof(s);
    //printf("size:%d\n", size);
    //printf("len:%d\n", len);
    int *str = (int *)malloc(sizeof(int) * (len + 1));
    char *str2 = (char *)malloc(sizeof(char) * (len + 1));
    int i = 0;
    int j = 1;
    //printf("haha\n");

    //如果字符串的长度为1或者2，则直接输出
    if ((len == 1) || (len == 2)) {
        return s;
    }

    if (numRows == 1) {
        return s;
    }

    while (i <= (len - 1)) {
        if(j == 1) {
            //printf("bbbb\n");
            while(j < numRows && (i < len)) {
                str[i] = j;
                i++;
                j++;
                //printf("i：%d\n", i);
                //printf("j：%d\n", j);
                //printf("*************\n");
            }
        }
        //return 0;
        if (j == numRows) {
            //printf("cccc\n");
            while((j > 1) && (i < len)) {
                str[i] = j;
                i++;
                j--;
                //printf("*************\n");
                //printf("i：%d\n", i);
                //printf("j：%d\n", j);
                //printf("*************\n");
            }
        }
        //return 0;
        //printf("i:%d\n", i);
    }
    printf("ahahah\n");
    str[i] = '\0'; 
    printf("bbb\n");
    int k = 0;
    for(j=1; j<=numRows; j++) {
        for(i=0; i<len; i++) {
            if (str[i] == j) {
                str2[k] = s[i];
                k++;
            }
        }
    }
    //printf("k:%d\n", k);
    str2[k] = '\0';

    for(i=0; i<len; i++) {
        //printf("numRows:%d\n", str[i]);
        //printf("i:%d\n", i);
    }
    return str2;
}

int main() {
    //char *s = "ABC";
    //int numRows = 1;
    char *s = "hjouvsuyoypayulyeimuotehzriicfskpggkbbipzzrzucxamludfykgruowzgiooobppleqlwphapjnadqhdcnvwdtxjbmyppphauxnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkchzdflilrjqfnxztqrsvbspkyhsenbppkqtpddbuotbbqcwivrfxjujjddntgeiqvdgaijvwcyaubwewpjvygehljxepbpiwuqzdzubdubzvafspqpqwuzifwovyddwyvvburczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveymqpxhlrnunyfdzrhbasjeuygafoubutpnimuwfjqsjxvkqdorxxvrwctdsneogvbpkxlpgdirbfcriqifpgynkrrefx";
    int numRows = 503;
    char *str;
    str = convert(s, numRows);
    printf("str:%s\n", str);
    return 0;
}