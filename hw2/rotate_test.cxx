#include <iostream>
#include <cmath>
using namespace std;

void rotate(double& x,double& y,double alpha) {
  double x0 = x, y0 = y, c = cos(alpha), s = sin(alpha);
  x = c * x0 - s * y0;
  y = s * x0 + c * y0;
  return;
}

#include <chrono>
using namespace std::chrono;
using myclock = steady_clock;

#define NREPS 10000000

int main() {

  double x=.5, y=.5, alpha=1.57;
  double x0 = x, y0 = y, cx = cos(alpha)*x0, cy = cos(alpha)*y0, sx = sin(alpha)*x0, sy = sin(alpha)*y0, x_new = cx - sy, y_new = sx + cy;
  auto starttime = myclock::now();
  for (int i=0; i<NREPS; i++)
    x = x_new;
    y = y_new;
  auto endtime = myclock::now();
  auto duration = endtime-starttime;
  auto u_duration = duration_cast<microseconds>(duration);
  printf("Done after %lld usec\n",u_duration.count());

  return 0;
}
