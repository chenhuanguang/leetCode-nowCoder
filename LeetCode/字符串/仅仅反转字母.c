void Swap(char* str, int idx1, int idx2)
{
    char tmp = str[idx1];
    str[idx1] = str[idx2];
    str[idx2] = tmp;
}

char * reverseOnlyLetters(char * S)
{
    int len = strlen(S);
    int head = 0;
    int tail = len - 1;

    while (head < tail)
    {
        while (head < tail && ((S[head] < 'A') || (S[head] < 'a' && S[head] > 'Z')))
        {
            ++head;
        }
        
        while (head < tail && ((S[tail] < 'A') || (S[tail] < 'a' && S[tail] > 'Z')))
        
        {
            --tail;
        }
        if (head >= tail)
            break;

        Swap(S, head, tail);
        ++head;
        --tail;
    }

    return S;
}