## Design Process

### 1. Motor Configuration Selection

Different motor counts and layouts were evaluated based on the main design requirements.

| Design Criterion | 2 Motors: Left–Right | 2 Motors: Front–Rear | 3 Motors | 4 Motors |
|---|---|---|---|---|
| **Mass** | ✓ Low | ✓ Low | Medium | ✗ High |
| **Power consumption** | ✓ Low | ✓ Low | Medium | ✗ High |
| **Mechanical complexity** | ✓ Simple | ✓ Simple | Medium | High |
| **Driving force / traction** | Medium | Medium | High | ✓ Highest |
| **Straight-line motion** | Sensitive to motor-speed mismatch | ✓ Better longitudinal alignment | Medium | Requires motor synchronisation |
| **Force symmetry** | ✓ Left–right symmetric | ✓ Along chassis centreline | Depends on layout | ✓ Symmetric |
| **Obstacle traversal** | Possible yaw on bump/ramp | ✓ Force aligned with travel direction | More wheel–obstacle interaction | More wheel–obstacle interaction |
| **Motor synchronisation** | Required between L/R motors | Less critical for heading | Difficult | Most difficult |
| **Control complexity** | Medium | ✓ Low | High | High |

**Selected: 2-motor front–rear configuration**

Main considerations:

- low mass and power consumption;
- simple mechanical and control architecture;
- driving force aligned with the direction of travel;
- reduced sensitivity to left–right motor-speed mismatch;
- fewer wheel–obstacle interactions when crossing the bump and ramp.

For a conventional left–right differential drive,

$$
v_L \neq v_R
\quad \Rightarrow \quad
\omega \neq 0
$$

where a small difference between the left and right wheel velocities may cause unwanted yaw.

Therefore, the **front–rear motor layout** was selected for more consistent straight-line motion on the obstacle course.

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
