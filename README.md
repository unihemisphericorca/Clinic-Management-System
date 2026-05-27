Clinic Management System
Overview
The Clinic Management System is a console-based application written in C. It enables clinic administrators to manage patient records, schedule appointments, record doctor visits, and search through accumulated records. The application utilizes text files for persistent data storage, ensuring information is saved across multiple runs.

Features
Patient Management: Add new patient profiles or update existing details like name, age, gender, and contact info.

Appointment Scheduling: Book appointments for specific dates, times, and doctors while automatically checking for scheduling conflicts.

Visit Records: Log visit details including symptoms, diagnosis, and prescribed medications for specific patients.

Search System: Search and display data from the records including specific patient details, appointments scheduled on a particular date, or the complete visit history of a patient.

File Structure and Storage
The system automatically creates and reads from three text files:

patients_data.txt: Stores basic demographic information of patients.

appointments.txt: Contains all planned appointments.

visit_records.txt: Keeps logs of past clinical visits and medical findings.

Technical Considerations and Limitations
Input Formatting: The current implementation relies heavily on specific delimiters (such as commas) appended to user input fields during data entry or searching. Ensure inputs match the requested format in the terminal prompts (e.g., adding a trailing comma if requested).

Whitespace Constraints: The use of standard string reading (scanf("%s", ...)) means inputs containing spaces (such as multi-word symptoms or doctor names) may cause data misalignment. Use single-word text or separate words with underscores.

File Reading Buffers: Fixed-size arrays are declared for reading records (e.g., maximum array size of 100 entries in the update function). Processing files with contents exceeding these limitations may result in memory issues.

How to Compile and Run
Prerequisites
A C compiler installed on your system (such as GCC, Clang, or MinGW).
