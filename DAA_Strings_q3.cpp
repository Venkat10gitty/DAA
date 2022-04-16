#include <iostream>
#include <cstring>
using namespace std;
 
void computeLPSArray(char* pat, int M, int* lps);

void KMPSearch(char* pat, char* txt, int n1, int n2)
{
    int z=0;
    int arr[3];
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    computeLPSArray(pat, M, lps);
 
    int i = 0; 
    int j = 0; 
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            arr[z] = i-j;
            z++;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    int s, s1;
    s = arr[0];
    s1 = arr[2];
    
    if(s == 0 && s1 == (n1 - n2)) {
        printf("\n\nYES, T is the First-Last text");
    } else {
        printf("\n\nNo, T is not the First-Last text");
    }
    
}
void computeLPSArray(char* pat, int M, int* lps)
{
    int len = 0;
 
    lps[0] = 0; 
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
int main()
{
    int size1, size2;
    cout<<"Enter the size of text T: \n";
    cin>>size1;
    cout<<"Enter the size of pattern P: \n";
    cin>>size2;
    char txt[size1], pat[size2];
    cout<<"Enter Text T: \n";
    cin>>txt;
    cout<<"Enter pattern P: \n";
    cin>>pat;
    KMPSearch(pat, txt, size1, size2);
    return 0;
}