#include <math.h>

double SourceQ_e (double x, double y, double t)
{
  double Q_e;
  double RHO;
  double U;
  double V;
  double P;
  RHO = r * rho_0 + rho_x * sin(a_rhox * PI * x / L) + rho_y * cos(a_rhoy * PI * y / L) + rho_t * sin(a_rhot * PI * t / L);
  U = u_0 + u_x * sin(a_ux * PI * x / L) + u_y * cos(a_uy * PI * y / L) + u_t * cos(a_ut * PI * t / L);
  V = v_0 + v_x * cos(a_vx * PI * x / L) + v_y * sin(a_vy * PI * y / L) + v_t * sin(a_vt * PI * t / L);
  P = p_0 + p_x * cos(a_px * PI * x / L) + p_y * sin(a_py * PI * y / L) + p_t * cos(a_pt * PI * t / L);
  Q_e = -a_px * PI * p_x * Gamma * U * sin(a_px * PI * x / L) / (Gamma - 0.1e1) / L + a_py * PI * p_y * Gamma * V * cos(a_py * PI * y / L) / (Gamma - 0.1e1) / L - a_ut * PI * u_t * RHO * U * sin(a_ut * PI * t / L) / L + a_vt * PI * v_t * RHO * V * cos(a_vt * PI * t / L) / L + (U * U + V * V) * a_rhox * PI * rho_x * U * cos(a_rhox * PI * x / L) / L / 0.2e1 - (U * U + V * V) * a_rhoy * PI * rho_y * V * sin(a_rhoy * PI * y / L) / L / 0.2e1 - a_pt * PI * p_t * sin(a_pt * PI * t / L) / (Gamma - 0.1e1) / L + (U * U + V * V) * a_rhot * PI * rho_t * cos(a_rhot * PI * t / L) / L / 0.2e1 + (0.4e1 * a_ux * a_ux * u_x * sin(a_ux * PI * x / L) + 0.3e1 * a_uy * a_uy * u_y * cos(a_uy * PI * y / L)) * PI * PI * mu * U * pow(L, -0.2e1) / 0.3e1 + (0.3e1 * a_vx * a_vx * v_x * cos(a_vx * PI * x / L) + 0.4e1 * a_vy * a_vy * v_y * sin(a_vy * PI * y / L)) * PI * PI * mu * V * pow(L, -0.2e1) / 0.3e1 + (0.3e1 * a_ux * u_x * cos(a_ux * PI * x / L) + a_vy * v_y * cos(a_vy * PI * y / L)) * PI * RHO * U * U / L / 0.2e1 - (a_uy * u_y * sin(a_uy * PI * y / L) + a_vx * v_x * sin(a_vx * PI * x / L)) * PI * RHO * U * V / L + (a_ux * u_x * cos(a_ux * PI * x / L) + 0.3e1 * a_vy * v_y * cos(a_vy * PI * y / L)) * PI * RHO * V * V / L / 0.2e1 - (0.4e1 * a_ux * a_ux * u_x * u_x * pow(cos(a_ux * PI * x / L), 0.2e1) - 0.4e1 * a_ux * a_vy * u_x * v_y * cos(a_ux * PI * x / L) * cos(a_vy * PI * y / L) + 0.3e1 * a_uy * a_uy * u_y * u_y * pow(sin(a_uy * PI * y / L), 0.2e1) + 0.6e1 * a_uy * a_vx * u_y * v_x * sin(a_uy * PI * y / L) * sin(a_vx * PI * x / L) + 0.3e1 * a_vx * a_vx * v_x * v_x * pow(sin(a_vx * PI * x / L), 0.2e1) + 0.4e1 * a_vy * a_vy * v_y * v_y * pow(cos(a_vy * PI * y / L), 0.2e1)) * PI * PI * mu * pow(L, -0.2e1) / 0.3e1 + (a_ux * u_x * cos(a_ux * PI * x / L) + a_vy * v_y * cos(a_vy * PI * y / L)) * PI * Gamma * P / (Gamma - 0.1e1) / L + (a_px * a_px * p_x * cos(a_px * PI * x / L) + a_py * a_py * p_y * sin(a_py * PI * y / L)) * k * PI * PI * pow(L, -0.2e1) / R / RHO - (a_rhox * a_rhox * rho_x * sin(a_rhox * PI * x / L) + a_rhoy * a_rhoy * rho_y * cos(a_rhoy * PI * y / L)) * k * PI * PI * P * pow(L, -0.2e1) / R * pow(RHO, -0.2e1) - (0.2e1 * a_px * a_rhox * rho_x * p_x * cos(a_rhox * PI * x / L) * sin(a_px * PI * x / L) + 0.2e1 * a_py * a_rhoy * rho_y * p_y * sin(a_rhoy * PI * y / L) * cos(a_py * PI * y / L)) * k * PI * PI * pow(L, -0.2e1) / R * pow(RHO, -0.2e1) - (0.2e1 * a_rhox * a_rhox * rho_x * rho_x * pow(cos(a_rhox * PI * x / L), 0.2e1) + 0.2e1 * a_rhoy * a_rhoy * rho_y * rho_y * pow(sin(a_rhoy * PI * y / L), 0.2e1)) * k * PI * PI * P * pow(L, -0.2e1) / R * pow(RHO, -0.3e1);
  return(Q_e);
}
