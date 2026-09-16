## Design Process

### 1. Motor Configuration Selection

Candidate drive layouts were compared assuming identical motors and wheels.

| Criterion | 2M: L–R | 2M: F–R | 3M: 2F+1R | 3M: 1F+2R | 4M: 2F+2R |
|---|---|---|---|---|---|
| **Added mass** | Low | **Low** | Medium | Medium | High |
| **L/R speed mismatch** | Causes yaw | **No L/R drive pair** | Causes yaw | Causes yaw | Requires L/R matching |
| **Fore–aft symmetry** | Medium | **High** | Low | Low | High |
| **Implementation complexity** | Low | **Low** | Medium | Medium | High |

For a left–right drive,

$$
\omega \approx \frac{v_R-v_L}{b}
$$

so unequal left–right wheel speeds introduce yaw.

**Selected: 2-motor front–rear configuration**

It combines low mass and complexity with no L/R drive mismatch and high fore–aft symmetry for bidirectional motion.

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
