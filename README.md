# Physiotherapy Center Management System

## 📋 Project Overview

This project presents a comprehensive simulation and management system for a physiotherapy center, designed to optimize patient scheduling, resource allocation, and operational efficiency. The system models real-world physiotherapy center operations with advanced handling of patient scheduling complexities including reschedules, late arrivals, and cancellations. Built as a practical application of fundamental data structures, primarily utilizing stacks and queues with additional functionality.

## 🎯 Objectives

- **Apply Data Structures**: Implement fundamental data structures in a real-world healthcare scenario
- **Patient Queue Management**: Use queue data structures for efficient patient flow management
- **Schedule Data Organization**: Organize appointment data using appropriate data structures
- **Handle Schedule Disruptions**: Manage reschedules, cancellations, and late arrivals using structured approaches
- **Demonstrate Practical Implementation**: Show how basic data structures solve complex operational problems

## 🔧 Key Features

### Core Data Structure Applications
- **Queue Management**: Patient waiting queues and priority queues for efficient patient flow
- **Stack Operations**: Finish list for all patients 
- **Enhanced Queues**: Specialized queue implementations with additional features for patient priorities
- **Derived Structures**: Custom data structures built upon basic stacks and queues to handle complex scheduling scenarios

### Schedule Management Features
- **Rescheduling Handler**: Stack-based appointment modification system with undo capabilities
- **Late Patient Processing**: Queue reordering for late arrivals with penalty tracking
- **Cancellation Management**: Efficient removal and waitlist promotion using queue operation

### System Functionality
- **Patient Registration**: Structured data entry and storage
- **Appointment Booking**: Schedule management using calendar data structures
- **Resource Allocation**: Therapist assignment using structured approaches
- **Waitlist Management**: Queue-based patient waiting systems
- **Report Generation**: Data traversal and analysis for operational insights

## 📊 Simulation Outputs

The system generates simulation samples demonstrating all patients statistics and analysis:

### Sample Simulation Results

**Patient Scheduling Data Overview:**
![Patient Data Table](https://github.com/Ibrahim-Abohola/Physiotherapy-Center-Project/blob/main/patient_data_sample.png)

*This sample shows the structured organization of patient data including Patient ID (PID), patient type (N/R), arrival times, service durations, and scheduling status using array and linked list implementations.*

**Simulation Statistics Summary:**
![Simulation Summary](https://github.com/Ibrahim-Abohola/Physiotherapy-Center-Project/blob/main/simulation_summary.png)

*Comprehensive statistical output demonstrating how data structures efficiently process and analyze patient flow, scheduling patterns, and operational metrics.*

### Data Structure Performance Metrics
Each simulation demonstrates:
- **Queue Operations**: Patient arrival and service processing
- **List Manipulations**: Schedule modifications and updates  
- **Search Efficiency**: Patient lookup and appointment retrieval
- **Data Organization**: Structured storage and retrieval of patient information
- **Memory Management**: Efficient use of data structures for optimal performance

## 💻 Technical Implementation

### Data Structures Used

1. **Queues and Enhanced Queues**
   - Patient waiting queues with FIFO operations
   - Queues for handling wating lists and all patients list
   - Priority queues for Treatment, early, late lists
   
   

2. **Stack**
   - used in finish list of Patients so that the patients who finished last appear first in the ouput file 

3. **Derived Data Structures**
   - Custom queue implementations with priority and penalty features
   - Drived priority queues to do some functionalities
   - Specialized containers for appointment and patient management

### Core Operations
- **Queue Operations**: Enqueue/dequeue for patient arrival and service
- **Stack Operations**: Push/pop for operation history and undo functionality
- **Priority Management**: Enhanced queue operations with priority handling
- **Schedule Modifications**: Stack-based tracking of appointment changes
- **Patient Flow Control**: Coordinated stack and queue operations for optimal patient management


### Installation
```bash
git clone https://github.com/Ibrahim-Abohola/Physiotherapy-Center-Project.git
cd Physiotherapy-Center-Project
# Follow setup instructions in the repository
```

### Usage
1. **Initialize Data Structures**: Set up the required queues and stacks with additional functionality
2. **Load Patient Data**: Import patient information using queue-based intake system
3. **Run Scheduling Operations**: Execute appointment booking using stack and queue operations
4. **Process Schedule Changes**: Handle reschedules and cancellations using coordinated stack/queue operations
5. **Generate Reports**: Process data through stack and queue traversals to produce operational summaries

## 👥 Team Members

This project was developed by:

- **Ibrahim Abohola** - [@Ibrahim-Abohola](https://github.com/Ibrahim-Abohola)
- **Ebraam Ashraf** - [@Ebraam-Ashraf](https://github.com/Ebraam-Ashraf)
- **Ahmed Maged** - [@AhmedMaged239](https://github.com/AhmedMaged239)

---

*This project serves as a practical demonstration of how fundamental data structures can be effectively applied to solve real-world problems in healthcare management, specifically focusing on physiotherapy center operations including patient scheduling, rescheduling, and late arrival handling.*
