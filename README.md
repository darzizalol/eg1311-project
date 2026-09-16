## Design Process

### 1. Motor Configuration Selection

Four candidate drive configurations were considered under the same motor and wheel assumptions.

| Criterion | 2M: Left–Right | 2M: Front–Rear | 3M | 4M |
|---|---|---|---|---|
| **Mass / power demand** | Low | **Low** | Medium | High |
| **L/R speed mismatch** | Causes yaw | **No L/R drive pair** | Layout-dependent | Requires L/R matching |
| **Straight-line robustness** | Low | **High** | Layout-dependent | Medium |
| **Fore–aft symmetry** | Layout-dependent | **High** | Low / layout-dependent | High |
| **Forward–reverse suitability** | Medium | **High** | Layout-dependent | High |
| **Implementation complexity** | Low | **Low** | Medium | High |

For a left–right drive,

$$
\omega \approx \frac{v_R-v_L}{b}
$$

so any left–right speed mismatch directly introduces a yaw rate.

**Selected: 2-motor front–rear configuration**

It provides low mass and complexity while avoiding L/R motor-induced yaw and maintaining a symmetric drivetrain for both forward and reverse motion.

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
