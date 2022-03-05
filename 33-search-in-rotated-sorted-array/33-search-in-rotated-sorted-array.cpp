class Solution {
public:
    int search(vector<int>& arr, int target) {
       int l=0,h=arr.size()-1,m;
        if(l==h)
            return arr[0]==target?0:-1;
        while(l<=h)
        {
            // cout<<l<<" "<<h<<endl;
            m=(l+h)/2;
            if(arr[l]>arr[m])//m is in second half
            {
                h=m-1;
            }
            else if(arr[m]>arr[h])//m is in first half
            {
                l=m+1;
            }
            else
            {
                if(l>1&&arr[l-1]>arr[l])
                    m=l;
                else if(h<arr.size()-1&&arr[h]>arr[h+1])
                    m=h+1;
                else if(arr[l]>arr[h])//decreasing sorted
                    m=h;
                else if(arr[l]<arr[h])
                    m=l;
                break;
            }
        }
        int  l1=0,h1=m-1,l2=m,h2=arr.size()-1;
       // cout<<l1<<" "<<h1<<endl;
       //  cout<<l2<<" "<<h2<<endl;
        
         if(l1<=h1&&arr[l1]<=target&&target<=arr[h1])
         {
             while(l1<=h1)
             {
                 m=(l1+h1)/2;
                 if(arr[m]==target)
                     return m;
                 else if(arr[m]>target)
                     h1=m-1;
                 else
                     l1=m+1;
             }
              
         }
        else if(l2<=h2&&arr[l2]<=target&&target<=arr[h2])
        {
            while(l2<=h2)
             {
                 m=(l2+h2)/2;
                 if(arr[m]==target)
                     return m;
                 else if(arr[m]>target)
                     h2=m-1;
                 else
                     l2=m+1;
             }
        }
            return -1;
        // while
        // while(l<h)
        // {
        //     cout<<l<<" "<<h<<endl;
        //     m=(l+h)/2;
        //     if(arr[m]==target)
        //         return m;
        //     else if(arr[m]<target)
        //     {
        //         if(arr[l]>arr[h])
        //         {
        //             if(arr[l]<arr[m])//first slope
        //                 l=m+1;
        //             else if(arr[m]<arr[h])//second slope
        //                 l=m+1; 
        //             else      
        //                 h=m-1;
        //         }
        //         else
        //            l=m+1;
        //     }
        //     else
        //     {
        //         if(arr[l]>arr[h])
        //         {
        //             if(arr[l]<=target)//first slope
        //                 h=m-1;
        //             else if(arr[m]<arr[h])//second slope
        //                 h=m-1; 
        //             else      
        //                 l=m+1;
        //         }
        //         else
        //            h=m-1;
        //     }
        // }
        // cout<<l<<" "<<h<<endl;
        // if(h>=0&&target==arr[h])
        //     return h;
        // else if(l<arr.size()&&target==arr[l])
        //     return l;
        // else
        //     return -1;
        // return m;
    }
};