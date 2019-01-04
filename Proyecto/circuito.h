bool f47(int n)
{
	return not ( n&(1<<15) );
}

bool f46(int n)
{
	return not ( n&(1<<14) );
}

bool f45(int n)
{
	return not ( n&(1<<7) );
}

bool f44(int n)
{
	return f45(n) or ( n&(1<<12) );
}

bool f43(int n)
{
	return not ( n&(1<<9) );
}

bool f42(int n)
{
	return not ( n&(1<<6) );
}

bool f41(int n)
{
	return ( n&(1<<6) ) or f47(n);
}

bool f40(int n)
{
	return ( n&(1<<15) ) or ( n&(1<<14) );
}

bool f39(int n)
{
	return not ( n&(1<<13) );
}

bool f38(int n)
{
	return ( n&(1<<9) ) or ( n&(1<<11) );
}

bool f37(int n)
{
	return not ( n&(1<<10) );
}

bool f36(int n)
{
	return not ( n&(1<<8) );
}

bool f35(int n)
{
	return not ( n&(1<<5) );
}

bool f34(int n)
{
	return ( n&(1<<1) ) or ( n&(1<<0) );
}

bool f33(int n)
{
	return f41(n) and f40(n);
}

bool f32(int n)
{
	return f46(n) or ( n&(1<<13) );
}

bool f31(int n)
{
	return ( n&(1<<11) ) or ( n&(1<<10) );
}

bool f30(int n)
{
	return f37(n) or f43(n);
}

bool f29(int n)
{
	return ( n&(1<<9) ) or ( n&(1<<8) );
}

bool f28(int n)
{
	return f42(n) or ( n&(1<<6) );
}

bool f27(int n)
{
	return not ( n&(1<<4) );
}

bool f26(int n)
{
	return ( n&(1<<3) ) or ( n&(1<<2) );
}

bool f25(int n)
{
	return not ( n&(1<<3) );
}

bool f24(int n)
{
	return not ( n&(1<<1) );
}

bool f23(int n)
{
	return f33(n) and f32(n);
}

bool f22(int n)
{
	return f34(n) or f45(n);
}

bool f21(int n)
{
	return f44(n) and f38(n);
}

bool f20(int n)
{
	return f30(n) and f31(n);
}

bool f19(int n)
{
	return f43(n) or ( n&(1<<8) );
}

bool f18(int n)
{
	return f36(n) or ( n&(1<<7) );
}

bool f17(int n)
{
	return ( n&(1<<6) ) or ( n&(1<<5) );
}

bool f16(int n)
{
	return f35(n) or ( n&(1<<4) );
}

bool f15(int n)
{
	return f27(n) or f25(n);
}

bool f14(int n)
{
	return f25(n) or f24(n);
}

bool f13(int n)
{
	return f23(n) and f22(n);
}

bool f12(int n)
{
	return f19(n) and f29(n);
}

bool f11(int n)
{
	return f18(n) and f28(n);
}

bool f10(int n)
{
	return f17(n) and f16(n);
}

bool f9(int n)
{
	return f15(n) and f26(n);
}

bool f8(int n)
{
	return f14(n) and f34(n);
}

bool f7(int n)
{
	return f13(n) and f21(n);
}

bool f6(int n)
{
	return f20(n) and f12(n);
}

bool f5(int n)
{
	return f11(n) and f10(n);
}

bool f4(int n)
{
	return f9(n) and f8(n);
}

bool f3(int n)
{
	return f7(n) and f6(n);
}

bool f2(int n)
{
	return f5(n) and f4(n);
}

bool f1(int n)
{
	return f3(n) and f2(n);
}