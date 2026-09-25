## Design Process

### 1. Motor Configuration Selection

Candidate drive layouts were compared assuming identical motors and wheels.

| Criterion | 2M: L–R | 2M: F–R | 3M: 2F+1R | 3M: 1F+2R | 4M: 2F+2R |
|---|---|---|---|---|---|
| **Added mass** | Low | Low | Medium | Medium | High |
| **L/R speed mismatch** | Causes yaw | No L/R drive pair | Causes yaw | Causes yaw | Requires L/R matching |
| **Fore–aft symmetry** | High | High | Low | Low | High |
| **Static stability** | Low | Low | Medium | Medium | High |
| **Implementation complexity** | Low | Low | Medium | Medium | High |

For a left–right drive,

$$
\omega \approx \frac{v_R-v_L}{b}
$$

Thus, unequal left–right wheel speeds directly introduce yaw.

**Selected: 2-motor front–rear configuration**

It provides low mass and complexity, avoids L/R motor-speed mismatch, and maintains good fore–aft symmetry for bidirectional motion.

---

### 2. Physics-Based Analysis

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

<p align="center">
<img width="600" alt="image" src="https://github.com/user-attachments/assets/e077bb53-f559-4c03-b083-926cba7dbf62" />
</p>

$$
\begin{aligned}
R
&\le \sqrt{W^{2}+h^{2}} \sin(\theta-\alpha) \\
&= \sqrt{W^{2}+h^{2}} \left( \sin\theta\cos\alpha-\cos\theta\sin\alpha \right) \\
&= \sqrt{W^{2}+h^{2}} \left( \sin\theta\frac{W}{\sqrt{W^{2}+h^{2}}} - \cos\theta\frac{h}{\sqrt{W^{2}+h^{2}}} \right) \\
&= W\sin\theta - h\cos\theta
\end{aligned}
$$

$$
\begin{aligned}
h &\le W\tan\theta - R\sec\theta
\end{aligned}
$$

---

### 3. MATLAB Simulation

MATLAB was used to simulate obstacle crossing and evaluate:

$$
(x,y,\theta), \quad C_{\min}
$$

where $C_{\min}$ is the minimum chassis clearance.


https://github.com/user-attachments/assets/dc3acbc7-a89f-401c-93c2-463e7c6e55ca


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

---

### 5. Prototype & Testing

**Physics → Simulation → Design → Prototype → Testing**

The physical prototype was tested and refined based on experimental results.
