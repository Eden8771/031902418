#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct MGC;
struct MGC
{
	int line = 0;
	int line = 0; 
	wstring b, m;  
}find[10005];
int main()
{
	struct MGC find[10005];
	locale china("zh_CN.UTF-8");
	string words, orgs, answer;
	cin >> words; cin >> orgs; cin >> answer;
	wifstream infile2;
	infile2.open(orgs);
	infile2.imbue(china);
	wstring a;
	unsigned int line1 = 0, total = 0; 
	wofstream woutfile;
	woutfile.open(answer);
	woutfile.imbue(china);
	while (getline(infile2, a))
	{
		line1++;
		for (unsigned int i = 0; i < a.size(); i++) {
			wifstream infile1;
			infile1.open(words);
			infile1.imbue(china);
			wstring b;
			while (getline(infile1, b))
			{
				if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
				{
					unsigned int	k = 0, len = 0, count;
					while (k < b.size() && i + len < a.size())
					{
						if (b[k] == a[i + len] || b[k] == a[i + len] + 32 || b[k] == a[i + len] - 32)
							k++, len++, count = 0;
						else
						{
							if (a[i + len] >= 0 && a[i + len] <= 126
								&& !((a[i + len] >= 'a' && a[i + len] <= 'z') || (a[i + len] >= 'A' && a[i + len] <= 'Z')) && k != 0) 
								len++, count++;
							else break;
							if (count > 20) break;
						}
					}
					if (k == b.size()) {
						find[total].line = line1;
						find[total].b = b;
						for (unsigned int k = i; k < i + len; k++)
						{
							if (k == 0)find[total].m = a[k];
							else find[total].m += a[k];
						}
						total++;
					}
				}
				else {
					unsigned int	k = 0, len = 0, count = 0;
					while (k < b.size() && i + len < a.size())
					{
						if (b[k] == a[i + len])
							k++, len++, count = 0;
						else
						{
							if (a[i + len] >= 0 && a[i + len] <= 126
								&& !((a[i + len] >= 'a' && a[i + len] <= 'z') || (a[i + len] >= 'A' && a[i + len] <= 'Z')) && k != 0)len++, count++;
							else break;
						}
						if (count > 20) break;
					}
					if (k == b.size()) {
						find[total].line = line1;
						find[total].b = b;
						for (unsigned int k = i; k < i + len; k++)
						{
							if (k == 0)find[total].m = a[k];
							else find[total].m += a[k];
						}
						total++;
					}
				}
			}
		}
	}
	woutfile << "Total:" << total << endl;
	for (unsigned int i = 0; i < total; i++) {
		woutfile << "Line" << find[i].line << ": <";
		woutfile << find[i].b;
		woutfile << "> ";
		woutfile << find[i].m;
		woutfile << endl;
	}
	woutfile.close();
	return 0;
}
