## Design Process

### 1. Motor Configuration Selection

Four candidate motor configurations were considered.  
The comparison assumes identical motors and comparable wheel sizes.

| Criterion | 2M: Left–Right | 2M: Front–Rear | 3M | 4M |
|---|---|---|---|---|
| **Motor count** | 2 | 2 | 3 | 4 |
| **Added motor mass** | Low | Low | Medium | High |
| **Power demand** | Low | Low | Medium | High |
| **Drive symmetry** | Left–right symmetric | Longitudinally symmetric | Layout-dependent | High |
| **Sensitivity to motor-speed mismatch** | High — causes yaw | Low — mainly causes wheel slip | Medium | High |
| **Traction potential** | Medium | Medium | High | Highest |
| **Motor synchronisation** | L/R speed matching required | Less critical for heading | Required | Strongly required |
| **Control complexity** | Medium | Low | High | High |
| **Wheel–obstacle interaction** | 2 driven contact points | 2 driven contact points | 3 driven contact points | 4 driven contact points |
| **Mechanical complexity** | Low | Low | Medium | High |

**Selected configuration: 2-motor front–rear drive**

For a left–right drive, a wheel-speed mismatch

$$
v_L \neq v_R
$$

produces a non-zero yaw rate,

$$
\omega \neq 0,
$$

which may cause deviation from straight-line motion under open-loop control.

The front–rear configuration was therefore selected to reduce heading sensitivity to motor-speed mismatch while maintaining low mass, low power demand, and low mechanical complexity.

---

### 2. Physics-Based Design

Key parameters:

$$
R = \text{wheel radius}, \quad
L = \text{chassis length}, \quad
H = \text{chassis height}
$$

Obstacle-clearance constraint:

$$
H_{\min} = f(R,L)
$$

---

### 3. MATLAB Simulation

MATLAB was used to simulate obstacle crossing and evaluate:

$$
(x,y,\theta), \quad C_{\min}
$$

where $C_{\min}$ is the minimum chassis clearance.

---

### 4. Parameter Selection

Design constraints:

$$
H_1 = f(R)
$$

$$
H_2 = g(R)
$$

The intersection / feasible region was used to select the final design parameters:

$$
R^*, \quad L^*, \quad H^*
$$

---

### 5. Prototype & Testing

**Physics → Simulation → Design → Prototype → Testing**

The physical prototype was tested and refined based on experimental results.
