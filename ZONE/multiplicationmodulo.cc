LL mulmod(LL a,LL b,LL c)
{
    LL x,y;
    x = 0;
    y = a%c;
    while(b>0)
    {
        if(b%2)
            x = (x+y)%c;
        y = (y<<1)%c;
        b >>=1;
    }
    return x%c;
}
