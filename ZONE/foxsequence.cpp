    #include<cstdio>
    #include<string>
    #include<vector>
    using namespace std;

    class FoxSequence
    {
    public:
        string isValid(vector<int> arr)
        {
            int cd,a,b,c,d,i;
            int n = arr.size();
            if(n<5)
                return "NO";
            else
            {
                i=0;
                cd = arr[i+1]-arr[i];
                if(cd<1)
                {
                    return "NO";
                }
                else
                {
                    while(i<n-2 && cd==arr[i+1]-arr[i])
                    {
                        i++;
                    }
                    a = i;
                    if(a==0)
                    {
                        return "NO";
                    }
                    else
                    {
                        if(a==n-2)
                            return "NO";
                        else
                            cd = arr[i+1]-arr[i];
                        if(cd>1)
                            return "NO";
                        else
                        {
                            while(i<n-1 && cd==arr[i+1]-arr[i])
                            {
                                i++;
                            }
                            b = i;
                            if(a==b)
                            {
                                return "NO";
                            }
                            else
                            {
                                cd = arr[i];
                                while(i<n && cd==arr[i])
                                {
                                    i++;
                                }
                                c = i;
                                if(i<n-2)
                                {
                                    cd = arr[i+1]-arr[i];
                                    if(cd<1)
                                        return "NO";
                                }
                                else
                                    return "NO";
                                while(i<n-1 && cd==arr[i+1]-arr[i])
                                    i++;
                                d = i;
                                if(i<=n-2)
                                    cd = arr[i+1]-arr[i];
                                else
                                    return "NO";
                                while(i<=n-2 && cd==arr[i+1]-arr[i])
                                    i++;
                                if(i==n-1)
                                    return "YES";
                                else
                                    return "NO";
                            }
                        }
                    }
                }

            }

        }
    };
