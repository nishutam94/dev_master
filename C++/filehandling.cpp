#include<bits/stdc++.h>
using namespace std;

class filehandle
{
    public:
    void writtingtofile()
    {
        ofstream file1;
        file1.open("file1.txt");
        string line;
        while (file1)
        {
            getline(cin,line);
            if (line == "-1")
            {
                break;
            }

            file1<<line<<'\n';
        }
        file1.close();
    }

   void readingtofile()
    {
        ifstream file2;
        file2.open("file1.txt");
        string line;
        while (getline(file2,line))
        {
            cout<<line<<endl;
        }
        file2.close();
    }

};




int main()
{
    filehandle f1;
    f1.writtingtofile();
    f1.readingtofile();


    return 0;
}