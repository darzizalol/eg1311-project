## Design Process

### 1. Motor Configuration Selection

Four candidate drive configurations were considered under the same motor and wheel assumptions.

| Criterion | 2M: Left–Right | 2M: Front–Rear | 3M | 4M |
|---|---|---|---|---|
| **Mass / power demand** | Low | **Low** | Medium | High |
| **Sensitivity to L/R speed mismatch** | High — induces yaw | **Low — no L/R drive pair** | Layout-dependent | Requires L/R matching |
| **Fore–aft symmetry / bidirectional suitability** | Layout-dependent | **High** | Layout-dependent | High if symmetrically arranged |
| **Implementation complexity** | Low | **Low** | Medium | High |

For a left–right drive,

$$
\omega \approx \frac{v_R-v_L}{b}
$$

so a left–right speed mismatch directly introduces yaw.

**Selected: 2-motor front–rear configuration**

It provides low mass and complexity, avoids L/R motor-induced yaw, and preserves fore–aft symmetry for bidirectional motion.

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
