int myStrlen(char s[], int k)
{
    k = 0;
    while (s[k] != '\0')
    {
        k ++;
    }
    return k;
}

int myStrcmp(char s1[MAX], char s2[MAX])
{
    int i = 0;
    if (s1[0] == '\n'||s1[0] == '\r')
    {
        return 0;
    }
    
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] < s2[i])
        {
            return -1;
        }else if (s1[i] > s2[i])
        {
            return 1;
        }
        i++;
    }

    if (s1[i] == '\0' && s2[i] == '\0')
    {
        return 0;
    } else if (s1[i] == '\0')
    {
        return -1;
    } else
    {
        return 1;
    }
}
void mySubstr(char s[], int b, int count, char ss[])
{
    int j = 0;
    for (int i = b; i < b + count; i++)
    {      
        ss[j] = s[i];
        j++;
    }
    ss[j] = '\0';
}
void DemTieng(char s1[])
{
    int k;
    int length = myStrlen(s1,k);
    while((length > 0) && (s1[length - 1] == '\r'||s1[length - 1] == '\n'))
    {
        s1[--length] ='\0';
    }
    char wordstorage[MAX][MAX];
    int f[MAX];
    int uniquewordcount = 0;
    char* token = strtok(s1, " ");
    while (token != nullptr)
    {
        bool maru = false;
        for (int i = 0; i < uniquewordcount; i++)
        {
            if (myStrcmp(wordstorage[i], token) == 0)
            {
                f[i]++;
                maru = true;
                break;
            }
        }
        if (!maru)
        {
            int tokenlength;
            mySubstr(token, 0, myStrlen(token,tokenlength), wordstorage[uniquewordcount]);
            f[uniquewordcount]++;
            uniquewordcount++;
        }
        token = strtok(nullptr, " ");
    }
    for (int i = 0; i < uniquewordcount; i++)
    {
        cout << wordstorage[i] << ": " << f[i] << endl;
    }

}