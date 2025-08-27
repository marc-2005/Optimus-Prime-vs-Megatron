# Optimus-Prime-vs-Megatron
THis is a file for a fight between Optimus Prime and Megatron
# 🤖 Transformers Battle: Optimus Prime vs Megatron

This is a simple **C++  battle** that simulates a battle between **Optimus Prime** and **Megatron** using **Object-Oriented Programming (OOP)** principles.


## 🎮 Gameplay
- Both Optimus Prime and Megatron start with **100 health**.
- Each fighter takes **turns to attack**.
- Weapons have different **damage values** and **accuracy rates**.
- After each round, the program shows the **remaining health** of both fighters.
- The battle ends when one (or both) drop to **0 health or below**.
- The program declares the **winner** at the end.

## 🔧 Features
- Abstraction, Inheritance, Polymorphism, and Encapsulation are applied.
- Weapons:
  - **Optimus Prime**
    - Ion Rifle (6 dmg, 100% accuracy)  
    - Energon Swords (12 dmg, 80% accuracy)  
    - Shoulder Cannon (45 dmg, 25% accuracy)  
  - **Megatron**
    - Fusion Cannon (9 dmg, 90% accuracy)  
    - Fusion Sword (18 dmg, 70% accuracy)  
    - Tank Mode (60 dmg, 15% accuracy)  
 
                             ┌────────────┐
                             │    Start   │   
                             └─────┬──────┘
                              │
                              ▼
            ┌─────────────────┐ ───────────> ┌─────────────────┐
              Optimus Turn    │     if alive   Megatron turn
            └─────┬─────┬─────┘ <─────────── └─────┬─────┬─────┘ 
                              │    │
                              ▼    ▼ 
                             ┌─────────────────┐
                                Check Winner 
                             └─────┬───────────┘
                                   │
                                   ▼
                               ┌────────────┐
                                   End 
                               └────────────┘