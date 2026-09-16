## Design Process

### 1. Motor Configuration Selection

Different motor counts and layouts were compared.

| Config. | Typical Layout | Pros | Cons |
|---|---|---|---|
| **2 motors** | 1 left + 1 right | Symmetric drive; simple differential steering; low mass; low power consumption; easy control | Lower total traction and torque |
| **3 motors** | 2 rear + 1 front / 2 front + 1 rear | Higher traction than 2 motors; more driving force available | Asymmetric force distribution; harder speed matching; more complex control; uneven load sharing |
| **4 motors** | 1 motor per wheel | Highest traction; high driving torque; good force distribution | Highest mass; high current consumption; more wiring; motor synchronization required |

**Selected: 2-motor differential drive**

Main reasons:

- symmetric force distribution;
- simplest control architecture;
- lower mass and power consumption;
- fewer motors to synchronise;
- sufficient torque for the obstacle course.

Motor layout:

$$
\text{Left Motor} \qquad \boxed{\text{Chassis}} \qquad \text{Right Motor}
$$

Steering is achieved by controlling the wheel speeds independently:

$$
v_L = v_R \Rightarrow \text{Straight}
$$

$$
v_L \neq v_R \Rightarrow \text{Turning}
$$
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
