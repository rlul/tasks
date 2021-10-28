#include <iostream>

#define currency(_cur, _rate)	struct _cur ## _t { static double rate; }; \
								double _cur ## _t::rate = _rate;

template<typename T1, typename T2>
double convert(const double& convertable) {
	return convertable / T1::rate * T2::rate;
}

template<typename TRes, typename T1, typename T2, typename T3>
double add_up(double currency_a, double currency_b, double currency_c) {
	return convert<T1, TRes>(currency_a) + convert<T2, TRes>(currency_b), convert<T3, TRes>(currency_c);
}

currency(usd, 1);	// Chosen as base currency
currency(rub, 75);
currency(byn, 2.5);

int main() {

	double in_usd = 2.5;
	double in_rub = 1000;
	double in_byn = 30;
	printf("%.1f USD = %.1f RUB\n", in_usd, convert<usd_t, rub_t>(in_usd));
	printf("%.1f RUB = %.1f USD\n", in_rub, convert<rub_t, usd_t>(in_rub));
	printf("%.1f BYN = %.1f RUB\n", in_byn, convert<byn_t, rub_t>(in_byn));

	printf("\n%.1f USD + %.1f RUB + %.1f BYN = %.1f USD\n"
		, in_usd, in_rub, in_byn, add_up<usd_t, usd_t, rub_t, byn_t>(in_usd, in_rub, in_byn));

	return 0;
}