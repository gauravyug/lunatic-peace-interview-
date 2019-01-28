void occurredOnce(int arr[], int n) 
{ 
	// Sort the array 
	sort(arr, arr + n); 

       int flag = 0;

       for (int i = 0; i< n;++i)
       {
               if (arr[i] == arr[i+1])
               {
                       flag = 1;
                       ++i;
                       continue;
               }
               else{
                       flag = 0;
                       printf("%d ", arr[i]);
               }
       }
} 