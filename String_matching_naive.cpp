#include <iostream>
#include <cstring>
using namespace std;

void search(char* pat, char* txt)
{
    int flag =0;
	int M = strlen(pat);
	int N = strlen(txt);
	for (int i = 0; i <= N - M; i++) {
	    
		int j;
		for (j = 0; j < M; j++) {
			if (txt[i + j] != pat[j])
				break;
		}
		if (j == M) {
		   
			printf("%d", i);
			flag++;
		}
		
	}
	if(flag==0) {
	    cout<<"Invalid";
	}
}

int main()
{
    char txt[20];
    char pat[20];
    cin>>txt;
    cin>>pat;
	search(pat, txt);
	return 0;
}
