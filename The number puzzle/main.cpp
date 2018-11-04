// The Number Puzzle
// 3 Nov 2018

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::string;

int load[5][7]={{76438, 52998, 28666, 10570, 11045, 13902, 12655},  \
                {48195, 3200, 63312, 70206, 64304, 76615, 57821},   \
                {90830, 40067, 62649, 78215, 82845, 9027, 4802},    \
                {17182, 50221, 91337, 1209, 20420, 60789, 39543},   \
                {90073, 69130, 12295, 10068, 82985, 89398, 97264}};

void printArray(int size, int array[])      // prints an array
{
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}


int _5sum(int array[])      // sums 5 element array
{
    int sum=0;
    for(int i=0;i<=4;i++)
    {
        sum+=array[i];
    }
    return(sum);
}

int _2sum(int array[])      // sums 2 array elements
{
    int sum=0;
    sum+=array[1];
    sum+=array[3];

    return(sum);
}

int digitSumMax=0;      // holds the largest Puzzle Score

int main()
{
    int source[5][7][5];            // holds fully populated detailed array
    int temp, flag, digitSum, winCount=0;

    for(int i=0;i<=4;i++)
    {
        for(int j=0;j<=6;j++)       // deconstruct numbers to digits
        {
            temp = load[i][j];
            source[i][j][4]=temp%10;
            temp=(temp-temp%10)/10;
            source[i][j][3]=temp%10;
            temp=(temp-temp%10)/10;
            source[i][j][2]=temp%10;
            temp=(temp-temp%10)/10;
            source[i][j][1]=temp%10;
            temp=(temp-temp%10)/10;
            source[i][j][0]=temp%10;
        }
    }

    for(int a=0;a<=4;a++)           // go through all permutations of numbers in puzzle grid
    {
        cout<<"Loop: "<<a<<endl;
        for(int b=0;b<=6;b++)
        {
            for(int c=0;c<=4;c++)
            {
                for(int d=0;d<=6;d++)
                {
                    for(int e=0;e<=4;e++)
                    {
                        for(int f=0;f<=6;f++)
                        {
                            for(int g=0;g<=4;g++)
                            {
                                for(int h=0;h<=6;h++)
                                {
                                    for(int m=0;m<=4;m++)
                                    {
                                        for(int n=0;n<=6;n++)
                                        {
                                            for(int q=0;q<=4;q++)
                                            {
                                                for(int r=0;r<=6;r++)
                                                {
                                                    flag=1;         // test puzzle intersection points per rules
                                                    if(source[a][b][0]!=source[g][h][0])flag=0;
                                                    if(source[a][b][2]!=source[m][n][0])flag=0;
                                                    if(source[a][b][4]!=source[q][r][0])flag=0;
                                                    if(source[c][d][0]!=source[g][h][2])flag=0;
                                                    if(source[c][d][2]!=source[m][n][2])flag=0;
                                                    if(source[c][d][4]!=source[q][r][2])flag=0;
                                                    if(source[e][f][0]!=source[g][h][4])flag=0;
                                                    if(source[e][f][2]!=source[m][n][4])flag=0;
                                                    if(source[e][f][4]!=source[q][r][4])flag=0;
                                                    if(flag==1)
                                                    {
                                                        cout<<"Winner! "<<endl<<endl;
                                                        winCount++;                 // total number of winners
                                                        cout<<a<<"  "<<b<<endl;     // display indicies for source array
                                                        cout<<c<<"  "<<d<<endl;
                                                        cout<<e<<"  "<<f<<endl;
                                                        cout<<g<<"  "<<h<<endl;
                                                        cout<<m<<"  "<<n<<endl;
                                                        cout<<q<<"  "<<r<<endl;
                                                        cout<<endl<<endl<<endl;

                                                        digitSum=0;         // sum answer digits from puzzle grid
                                                        digitSum+=_5sum(source[a][b]);
                                                        digitSum+=_5sum(source[c][d]);
                                                        digitSum+=_5sum(source[e][f]);
                                                        digitSum+=_2sum(source[g][h]);
                                                        digitSum+=_2sum(source[m][n]);
                                                        digitSum+=_2sum(source[q][r]);
                                                        cout<<digitSum<<endl<<endl;
                                                        digitSumMax=(digitSum>digitSumMax)? digitSum:digitSumMax;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<"Number of winners: "<<winCount<<endl;
    cout<<"Max score: "<<digitSumMax<<endl;
    return 0;
}
