
#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	for (int i = 0; i <= N - M; i++) {
		int j;
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;

		if (j == M) 
			printf("%d", i);
	}
}

int main()
{
	char txt[] = "abcabaabcabac";
	char pat[] = "abaa";
	search(pat, txt);
	return 0;
}

