#include <stdio.h>

int min(int a, int b) {
	return a<b?a:b;
}

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		char s[n+1];
		scanf(" %[^\n]", s);

		int lchars[26], uchars[26];
		for(int i=0; i<26; i++) {lchars[i]=0; uchars[i]=0;}
		for(int i=0; i<n; i++) {
			if(s[i]>='a' && s[i]<='z')
				lchars[s[i]-'a'] += 1;
			if(s[i]>='A' && s[i]<='Z')
				uchars[s[i]-'A'] += 1;
		}

		int pair_count = 0;
		for(int i=0; i<26; i++) {
			int m = min(lchars[i], uchars[i]);
			lchars[i] -= m;
			uchars[i] -= m;
			pair_count += m;

			int ik = k;
			k -= min(lchars[i]/2, k);
			k -= min(uchars[i]/2, k);
			pair_count += ik-k;
		}

		printf("%d\n", pair_count);
	}
	
	return 0;
}
