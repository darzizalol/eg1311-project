## Design Process

### 1. Motor Configuration Selection

Four candidate motor configurations were considered.  
The comparison assumes identical motors and comparable wheel sizes.

| Criterion | 2M: Left–Right | 2M: Front–Rear | 3M | 4M |
|---|---|---|---|---|
| **Mass / power demand** | Low | Low | Medium | High |
| **Heading sensitivity to speed mismatch** | High | Low | Layout-dependent | Layout-dependent |
| **Drive-force potential** | Low–Medium | Low–Medium | Medium–High | High |
| **Implementation complexity** | Low | Low | Medium | High |

For a left–right drive, the robot yaw rate can be approximated by

$$
\omega = \frac{v_R-v_L}{b}
$$

where:

- $v_L$ = left-wheel velocity
- $v_R$ = right-wheel velocity
- $b$ = wheel separation
- $\omega$ = yaw rate

Therefore,

$$
v_L \neq v_R
\quad \Rightarrow \quad
\omega \neq 0
$$

A small speed mismatch between the left and right motors can therefore cause deviation from straight-line motion under open-loop control.

**Selected configuration: 2-motor front–rear drive**

The front–rear configuration was selected because it:

- maintains low mass and power demand;
- reduces heading sensitivity to motor-speed mismatch;
- requires fewer motors and simpler control;
- provides sufficient driving force for the obstacle course.

This configuration was then used as the basis for the wheel-size and chassis-geometry analysis.

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
