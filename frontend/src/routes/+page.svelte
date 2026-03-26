<script>
    let formData = {};

    const schools = ['University of Florida', 'Florida State University', 'University of Central Florida', 'University of Miami', 'University of South Florida', 'Florida International University', 'Florida Atlantic University', 'Florida Gulf Coast University', 'NOVA Southeastern University', 'University of North Florida'];
    const departments = ['Computer Science', 'Computer Engineering', 'Mechanical Engineering', 'Aerospace Engineering', 'Electrical Engineering', 'Biomedical Engineering', 'Civil Engineering', 'Chemical Engineering', 'Nuclear Engineering', 'Physics'];
    const categories = ['Distributed Vision', 'Machine Learning', 'Computer Vision', 'Natural Language Processing', 'Human-Computer Interation', 'Embedded Systems Design', 'Computer Architecture Optimization', 'Autonomous Systems', 'IoT Security', 'Microelectronics', 'Fluid Dynamics', 'Thermodynamics and Heat Transfer', 'Additive Manufacturing', 'Robotics and Mechatronics', 'Vibrations and Control Systems', 'Aerodynamics', 'Propulsion Systems', 'Flight Dynamics and Control', 'Spacecraft Design', 'Computational Fluid Dynamics', 'Signal Processing', 'Control Systems', 'Microelectronics and VLSI Design', 'Wireless Communications', 'Power Systems and Smart Grids', 'Medical Imaging', 'Biomaterials Development', 'Tissue Engineering', 'Neural Engineering', 'Bioinstrumentation', 'Structural Analysis', 'Transportation Systems', 'Geotechnical Engineering', 'Environmental Engineering', 'Construction Management', 'Process Design and Optimization', 'Reaction Engineering', 'Biochemical Engineering', 'Polymer Science', 'Separation Processes', 'Reactor Design', 'Radiation Detection and Measurement', 'Nuclear Materials', 'Nuclear Safety and Risk Analysis', 'Fusion Energy', 'Quantum Mechanics', 'Astrophysics', 'Particle Physics', 'Condensed Matter Physics', 'Optics and Photonics'];
    const studentLevels = ['Freshman', 'Sophomore', 'Junior', 'Senior'];

    function submit() {
        console.log(formData);
        // fix submit
    }
</script>

<main>
    <h1>Research Lab Matcher</h1>

    <form on:submit|preventDefault={submit}>
        <label>
            School
            <select bind:value={formData.school} required>
                <option value="" disabled selected>Select a school</option>
                {#each schools as school}
                    <option value={school}>{school}</option>
                {/each}
            </select>
        </label>

        <label>
            Department
            <select bind:value={formData.department} required>
                <option value="" disabled selected>Select a department</option>
                {#each departments as dept}
                    <option value={dept}>{dept}</option>
                {/each}
            </select>
        </label>

        <label>
            Category
            <select bind:value={formData.category} required>
                <option value="" disabled selected>Select a category</option>
                {#each categories as category}
                    <option value={category}>{category}</option>
                {/each}
            </select>
        </label>

        <label>
            Student level
            <select bind:value={formData.level} required>
                <option value="" disabled selected>Select a level</option>
                {#each studentLevels as level}
                    <option value={level}>{level}</option>
                {/each}
            </select>
        </label>

        <button type="submit">Enter</button>
    </form>
</main>