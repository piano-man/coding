int treasureHunt(int *arr)
{
    int l = sizeof(arr)/sizeof(arr[0]);
    int i;
    int rel[100000];
    int max = INT_MIN;
    int max2 = INT_MIN;
    int element;
    int flag = 0;
    int start;int end;
    vector<int> clash;
    vector<int> counts;
    int min = INT_MAX;
    memset(rel,0,sizeof(rel));
    for(i=0;i<l;i++)
    {
        rel[arr[i]]++;
        if(rel[arr[i]]>max)
        {
            max = rel[arr[i]];
            element = arr[i];
        }
        else if(rel[arr[i]]=max)
        {
            if(flag==0)
            {
                clash.push_back(element);
                clash.push_back(arr[i]);
                flag=1;
                max2 = max;
            }
            else
            {
                clash.push_back(arr[i]);
                max2 = max;
            }
        }
    }
    if(max>max2)
    {
        
        int k;
        int f = 0;
        for(i=0;i<l;i++)
        {
            if(arr[i]==element&&f=0)
            {
                start = i;
                end = i;
            }
            else if(arr[i]==element&&f!=0)
            {
                if(i>end)
                {
                    end = i;
                }
            }
        }
        min = end-start;
    }
    else
    {
        int s = clash.size();
        int k;
        for(k=0;k<clash.size();k++)
        {
            int m;
            int ele = clash[k];
            int f = 0;
            for(m=0;m<l;m++)
            {
                if(arr[m]==ele&&f=0)
                {
                    start = m;
                    end = m;
                    f=1
                }
                else if(arr[m]==ele&&f==1)
                {
                    if(m>end)
                    {
                        end = m;
                    }
                }
            }
            int tmin = end-start;
            if(tmin<min)
            {
                min = tmin;
            }
        }
    }

    return min;
}