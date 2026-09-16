# EG1311

## Design Process

### 1. Concept Selection
Compared 2-wheel, 3-wheel and 4-wheel configurations.

| Config. | Main Advantage | Main Drawback |
|---|---|---|
| 2W | Light & simple | Lower stability |
| 3W | More stable | Extra drag |
| 4W | High stability | Heavy & complex |

**Selected: 2-wheel configuration**

---

### 2. Physics-Based Design

Key design parameters:

\[
R=\text{wheel radius},\quad
L=\text{chassis length},\quad
H=\text{chassis height}
\]

The geometry was analysed to ensure sufficient obstacle clearance:

\[
H_{\min}=f(R,L)
\]

---

### 3. MATLAB Simulation

A MATLAB model was used to simulate the robot crossing the obstacle course.

Main outputs:

\[
(x,y,\theta),\quad \text{clearance},\quad \text{collision check}
\]

---

### 4. Parameter Selection

MATLAB was used to generate design curves:

\[
H_1=f(R),\qquad H_2=g(R)
\]

The feasible/intersection region was used to select:

\[
R^*,\quad L^*,\quad H^*
\]

---

### 5. Prototype & Testing

\[
\text{Physics}
\rightarrow
\text{Simulation}
\rightarrow
\text{Design}
\rightarrow
\text{Prototype}
\rightarrow
\text{Testing}
\]

The physical prototype was then tested and refined based on experimental results.
