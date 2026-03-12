<script>
    let formData = {};

    const schools = ['University of Florida', 'Florida State University', 'University of Central Florida'];
    const departments = ['Computer Science', 'Computer Engineering', 'Mechanical Engineering'];
    const categories = ['Cybersecurity', 'Machine Learning', 'Genetics'];
    const studentLevels = ['Freshman', 'Sophomore', 'Junior', "Senior", "Graduate"];

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