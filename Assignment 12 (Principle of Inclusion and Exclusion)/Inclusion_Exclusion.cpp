#include <iostream>
using namespace std;
class sports
{
private:
    int a[100];
    int n, k = 0;

public:
    void getdata();
    void intersection_2(sports &s1, sports &s2);
    void intersection_3(sports &s1, sports &s2, sports &s3);
    void unionall(sports &s1, sports &s2, sports &s3);
};

void sports ::getdata()
{

    cout << "Enter Number of students : " << endl;
    cin >> n;
    cout << "Enter Roll NO.: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter roll no of " << i + 1 << "data : ";
        cin >> a[i];
    }
}
void sports ::intersection_2(sports &s1, sports &s2)
{

    for (int i = 0; i < s1.n; i++)
    {
        for (int j = 0; j < s2.n; j++)
        {
            if (s1.a[i] == s2.a[j])
            {
                a[k] = s1.a[i];
                k++;
            }
        }
    }
    cout << k << endl;
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << endl;
    }
}
void sports ::intersection_3(sports &s1, sports &s2, sports &s3)
{
    int l = 0;
    for (int i = 0; i < s1.n; i++)
    {
        for (int j = 0; j < s2.n; j++)
        {
            for (int k = 0; k < s3.n; k++)
            {
                if (s1.a[i] == s2.a[j] && s1.a[i] == s3.a[k])
                {
                    a[l] = s1.a[i];
                    l++;
                }
            }
        }
    }
    cout << "Intersection is " << l << endl;

    for (int i = 0; i < l; i++)
    {
        cout << a[i] << endl;
    }
}
void sports ::unionall(sports &s1, sports &s2, sports &s3)
{
    for (int i = 0; i < s1.n; i++)
    {
        a[k] = s1.a[i];
        k++;
    }
    for (int j = 0; j < s2.n; j++)
    {
        int flag = 0;
        for (int i = 0; i < s1.n; i++)
        {
            if (a[i] == s2.a[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            a[k] = s2.a[j];
            k += 1;
        }
    }
    for (int j = 0; j < s3.n; j++)
    {
        int flag1 = 0;
        for (int i = 0; i < s1.n; i++)
        {
            if (a[i] == s3.a[j])
            {
                flag1 = 1;
                break;
            }
        }
        if (flag1 != 1)
        {
            a[k] = s3.a[j];
            k += 1;
        }
    }
    cout << "Array:" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\nvalue of k:" << k << endl;
}
int main()
{
    sports c, f, v, cf, cv, fv, cvf, uni;
    cout << "--Enter Roll no for Cricket-- " << endl;
    c.getdata();
    cout << "--Enter Roll no for Football--" << endl;
    f.getdata();
    cout << "--Enter Roll no for Volleyball-- " << endl;
    v.getdata();
    cout << "--Intersection of of Cricket and foot Ball is -- " ;
    cf.intersection_2(c, f);
    cout << "--Intersection of of Cricket and volley ball is -- " ;
    cv.intersection_2(c, v);
    cout << "--Intersection of of Volleyball and foot Ball is --" ;
    fv.intersection_2(f, v);
    cout << "--Common element in all is --" << endl;
    cvf.intersection_3(c, v, f);
    cout << "--Union is-- " << endl;
    uni.unionall(c, v, f);
}
