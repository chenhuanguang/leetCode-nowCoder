int add(int a, int b){

        if(b == 0)
            return a;
        int c = (unsigned int)(a & b) << 1; //进位
        int d = a ^ b;
        return add(d, c);

}