int num,i,count,n;
    cout << "Enter max range: ";
    cin >> n;
    //e.g: 9: i=4, num%2, num%3=0, num%4
    for(num = 1; num<=n; num++){
        count = 0;
        for(i=2; i<=num/2; i++){
            if(num%i==0){
                count++;
                break;
            }
        }
        if(count==0 && num != 1)
            //setw = sets the field width to be used on output operations.
            cout << num << setw(3);
    }
    return 0;

