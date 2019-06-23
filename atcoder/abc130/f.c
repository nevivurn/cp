#include <stdio.h>

#define INV 1000000000
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MAXINV(a, b) (a == INV) ? ((b == INV) ? INV : b) : ((b == INV) ? a : MAX(a, b))
#define MININV(a, b) (a == INV) ? ((b == INV) ? INV : b) : ((b == INV) ? a : MIN(a, b))

int xmaxv = INV, xminv = INV, xmaxl = INV, xmaxr = INV, xminl = INV, xminr = INV;
int ymaxh = INV, yminh = INV, ymaxu = INV, ymaxd = INV, yminu = INV, ymind = INV;

double eval(double t) {
	double xmax = xmaxv;
	if (xmaxr != INV) xmax = MAXINV(xmax, xmaxr+t);
	if (xmaxl != INV) xmax = MAXINV(xmax, xmaxl-t);

	double xmin = xminv;
	if (xminr != INV) xmin = MININV(xmin, xminr+t);
	if (xminl != INV) xmin = MININV(xmin, xminl-t);

	double ymax = ymaxh;
	if (ymaxu != INV) ymax = MAXINV(ymax, ymaxu+t);
	if (ymaxd != INV) ymax = MAXINV(ymax, ymaxd-t);

	double ymin = yminh;
	if (yminu != INV) ymin = MININV(ymin, yminu+t);
	if (ymind != INV) ymin = MININV(ymin, ymind-t);

	return (xmax-xmin) * (ymax-ymin);
}

int main(void) {
	int n;
	scanf("%d", &n);

	while (n--) {
		int x, y;
		char c;
		scanf("%d%d %c", &x, &y, &c);
		switch (c) {
			case 'U':
				if (xmaxv == INV || xmaxv < x) xmaxv = x;
				if (xminv == INV || xminv > x) xminv = x;
				if (ymaxu == INV || ymaxu < y) ymaxu = y;
				if (yminu == INV || yminu > y) yminu = y;
				break;
			case 'D':
				if (xmaxv == INV || xmaxv < x) xmaxv = x;
				if (xminv == INV || xminv > x) xminv = x;
				if (ymaxd == INV || ymaxd < y) ymaxd = y;
				if (ymind == INV || ymind > y) ymind = y;
				break;
			case 'L':
				if (ymaxh == INV || ymaxh < y) ymaxh = y;
				if (yminh == INV || yminh > y) yminh = y;
				if (xmaxl == INV || xmaxl < x) xmaxl = x;
				if (xminl == INV || xminl > x) xminl = x;
				break;
			case 'R':
				if (ymaxh == INV || ymaxh < y) ymaxh = y;
				if (yminh == INV || yminh > y) yminh = y;
				if (xmaxr == INV || xmaxr < x) xmaxr = x;
				if (xminr == INV || xminr > x) xminr = x;
				break;
		}
	}

	double min = eval(0);
	if (xmaxv != INV) {
		if (xmaxl != INV && xmaxv < xmaxl) min = MIN(min, eval(xmaxl-xmaxv));
		if (xmaxr != INV && xmaxv > xmaxr) min = MIN(min, eval(xmaxv-xmaxr));
	}
	if (xmaxl != INV && xmaxr != INV && xmaxl > xmaxr) min = MIN(min, eval(((double) xmaxl-xmaxr)/2));

	if (xminv != INV) {
		if (xminl != INV && xminv < xminl) min = MIN(min, eval(xminl-xminv));
		if (xminr != INV && xminv > xminr) min = MIN(min, eval(xminv-xminr));
	}
	if (xminl != INV && xminr != INV && xminl > xminr) min = MIN(min, eval(((double) xminl-xminr)/2));

	if (ymaxh != INV) {
		if (ymaxu != INV && ymaxh > ymaxu) min = MIN(min, eval(ymaxh-ymaxu));
		if (ymaxd != INV && ymaxh < ymaxd) min = MIN(min, eval(ymaxd-ymaxh));
	}
	if (ymaxu != INV && ymaxd != INV && ymaxd > ymaxu) min = MIN(min, eval(((double) ymaxd-ymaxu)/2));

	if (yminh != INV) {
		if (yminu != INV && yminh > yminu) min = MIN(min, eval(yminh-yminu));
		if (ymind != INV && yminh < ymind) min = MIN(min, eval(ymind-yminh));
	}
	if (yminu != INV && ymind != INV && ymind > yminu) min = MIN(min, eval(((double) ymind-yminu)/2));

	printf("%.9f\n", min);
}
