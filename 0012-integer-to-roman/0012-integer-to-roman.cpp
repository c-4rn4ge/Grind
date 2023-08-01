class Solution {
public:
    string one(int n)
    {
        if(n==1) return "I";
        if(n==2) return "II";
        if(n==3) return "III";
        if(n==4) return "IV";
        if(n==5) return "V";
        if(n==6) return "VI";
        if(n==7) return "VII";
        if(n==8) return "VIII";
        if(n==9) return "IX";
        return "";
    }
    string two(int n)
    {
        if(n==10) return "X";
        if(n==20) return "XX";
        if(n==30) return "XXX";
        if(n==40) return "XL";
        if(n==50) return "L";
        if(n==60) return "LX";
        if(n==70) return "LXX";
        if(n==80) return "LXXX";
        if(n==90) return "XC";
        return "";
    }
    string three(int n)
    {
        if(n==100) return "C";
        if(n==200) return "CC";
        if(n==300) return "CCC";
        if(n==400) return "CD";
        if(n==500) return "D";
        if(n==600) return "DC";
        if(n==700) return "DCC";
        if(n==800) return "DCCC";
        if(n==900) return "CM";
        return "";
    }
    string four(int n)
    {
        if(n==1000) return "M";
        if(n==2000) return "MM";
        if(n==3000) return "MMM";
        return "";
    }
    string intToRoman(int num) 
    {
        int k = 1;
        string s="",ans="";
        while(num!=0)
        {
            int rem = num % 10;
            int t = rem * k;
            num /=10;
            if(k==1) s = one(t);
            else if(k==10) s = two(t);
            else if(k==100) s = three(t);
            else if(k==1000) s = four(t);
            ans = s + ans;
            k *= 10;
        }
        return ans;
    }
};