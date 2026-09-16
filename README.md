## Design Process

### 1. Motor Configuration Selection

Different motor counts and layouts were compared.

| Config. | Typical Layout | Pros | Cons |
|---|---|---|---|
| **2 motors** | 1 front + 1 rear | <ul><li>Low mass</li><li>Low power consumption</li><li>Simple structure</li><li>Fewer components</li></ul> | <ul><li>Lower total traction</li><li>Lower available torque</li><li>More sensitive to weight distribution</li></ul> |
| **3 motors** | 2 front + 1 rear / 1 front + 2 rear | <ul><li>Higher driving force</li><li>Better traction</li><li>More flexible motor placement</li></ul> | <ul><li>Asymmetric force distribution</li><li>Uneven load sharing</li><li>Harder motor synchronisation</li><li>Higher mass and power consumption</li></ul> |
| **4 motors** | 2 front + 2 rear | <ul><li>Highest driving force</li><li>High traction</li><li>Balanced force distribution</li><li>Good load sharing</li></ul> | <ul><li>Highest mass</li><li>Highest power consumption</li><li>More wiring</li><li>More complex motor synchronisation</li></ul> |

**Selected: 2-motor front–rear configuration**

Main reasons:
- lower mass and power consumption;
- simpler mechanical structure;
- fewer motors to control and synchronise;
- sufficient driving force for the required obstacles;
- compact layout suitable for the chassis design.

**Main trade-off:**  
Lower driving force → wheel size, chassis geometry and weight distribution require further optimisation.

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
