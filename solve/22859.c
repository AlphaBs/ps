// https://www.acmicpc.net/problem/22859

#include <stdio.h>

char doc[1111111];
char buf[1111111];
int pos;

int moveUntil(char ch)
{
    int d = 0;
    while (doc[pos + d] != ch)
    {
        d++;
    }
    return d;
}

int putUntil(char ch)
{
    int d = 0;
    while (doc[pos + d] != ch)
    {
        putchar(doc[pos + d]);
        d++;
    }
    return d;
}

int main()
{
    fread(doc, 1, sizeof(doc), stdin);
    //fgets(doc, sizeof(doc), stdin);
    pos = 6; // <main>

    while (doc[pos + 1] == 'd') // <div
    {
        pos += moveUntil('"') + 1; // title="
        printf("title : ");
        pos += putUntil('"') + 2; // ">
        putchar('\n');
        while (doc[pos + 1] == 'p')
        {
            pos += 3; // <p>

            int bufLen = 0;
            int spaced = 1;
            while (1) // <p> 부터 </p> 만날때까지 반복
            {
                for (; doc[pos] != '<'; pos++)
                {
                    if (doc[pos] == ' ')
                    {
                        if (!spaced)
                        {
                            buf[bufLen++] = ' ';
                            spaced = 1;
                        }
                    }
                    else
                    {
                        buf[bufLen++] = doc[pos];
                        spaced = 0;
                    }
                }

                if (doc[pos + 1] == '/' &&
                    doc[pos + 2] == 'p' &&
                    doc[pos + 3] == '>')
                {
                    pos += 4; // </p>
                    break;
                }
                else
                {
                    pos += moveUntil('>') + 1;
                }
            }

            while (bufLen >= 0 && buf[bufLen - 1] == ' ')
                bufLen--;
            buf[bufLen] = '\0';
            puts(buf);
        }
        pos += 6; // </div>
    }
    return 0;
}