#include <stdio.h>

int main()
{
    int wires[10000];
    int totalWire = 0;

    int k, n;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &wires[i]);
        totalWire += wires[i];
    }

    int result = totalWire / n;
    while (1)
    {
        int newTotalWire = 0;
        int maxWireR = -1;
        int maxWireQ = -1;
        int maxWire = -1;
        for (int i = 0; i < k; i++)
        {
            int wireQ = wires[i] / result;
            int wireRemain = wires[i] % result;

            newTotalWire += wireQ;

            if (maxWireR < wireRemain)
            {
                maxWireR = wireRemain;
                maxWireQ = wireQ;
                maxWire = wires[i];
            }
        }

        if (newTotalWire >= n)
            break;

        result = maxWire / (maxWireQ + 1);
    }

    printf("%d", result);

    return 0;
}