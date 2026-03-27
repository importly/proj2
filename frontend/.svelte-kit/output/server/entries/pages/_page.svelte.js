import { a2 as ensure_array_like, e as escape_html } from "../../chunks/index.js";
function _page($$renderer) {
  let formData = {};
  const schools = [
    "University of Florida",
    "Florida State University",
    "University of Central Florida",
    "University of Miami",
    "University of South Florida",
    "Florida International University",
    "Florida Atlantic University",
    "Florida Gulf Coast University",
    "NOVA Southeastern University",
    "University of North Florida"
  ];
  const departments = [
    "Computer Science",
    "Computer Engineering",
    "Mechanical Engineering",
    "Aerospace Engineering",
    "Electrical Engineering",
    "Biomedical Engineering",
    "Civil Engineering",
    "Chemical Engineering",
    "Nuclear Engineering",
    "Physics"
  ];
  const categories = [
    "Distributed Vision",
    "Machine Learning",
    "Computer Vision",
    "Natural Language Processing",
    "Human-Computer Interation",
    "Embedded Systems Design",
    "Computer Architecture Optimization",
    "Autonomous Systems",
    "IoT Security",
    "Microelectronics",
    "Fluid Dynamics",
    "Thermodynamics and Heat Transfer",
    "Additive Manufacturing",
    "Robotics and Mechatronics",
    "Vibrations and Control Systems",
    "Aerodynamics",
    "Propulsion Systems",
    "Flight Dynamics and Control",
    "Spacecraft Design",
    "Computational Fluid Dynamics",
    "Signal Processing",
    "Control Systems",
    "Microelectronics and VLSI Design",
    "Wireless Communications",
    "Power Systems and Smart Grids",
    "Medical Imaging",
    "Biomaterials Development",
    "Tissue Engineering",
    "Neural Engineering",
    "Bioinstrumentation",
    "Structural Analysis",
    "Transportation Systems",
    "Geotechnical Engineering",
    "Environmental Engineering",
    "Construction Management",
    "Process Design and Optimization",
    "Reaction Engineering",
    "Biochemical Engineering",
    "Polymer Science",
    "Separation Processes",
    "Reactor Design",
    "Radiation Detection and Measurement",
    "Nuclear Materials",
    "Nuclear Safety and Risk Analysis",
    "Fusion Energy",
    "Quantum Mechanics",
    "Astrophysics",
    "Particle Physics",
    "Condensed Matter Physics",
    "Optics and Photonics"
  ];
  const studentLevels = ["Freshman", "Sophomore", "Junior", "Senior"];
  $$renderer.push(`<main><h1>Research Lab Matcher</h1> <form><label>School `);
  $$renderer.select({ value: formData.school, required: true }, ($$renderer2) => {
    $$renderer2.option({ value: "", disabled: true, selected: true }, ($$renderer3) => {
      $$renderer3.push(`Select a school`);
    });
    $$renderer2.push(`<!--[-->`);
    const each_array = ensure_array_like(schools);
    for (let $$index = 0, $$length = each_array.length; $$index < $$length; $$index++) {
      let school = each_array[$$index];
      $$renderer2.option({ value: school }, ($$renderer3) => {
        $$renderer3.push(`${escape_html(school)}`);
      });
    }
    $$renderer2.push(`<!--]-->`);
  });
  $$renderer.push(`</label> <label>Department `);
  $$renderer.select({ value: formData.department, required: true }, ($$renderer2) => {
    $$renderer2.option({ value: "", disabled: true, selected: true }, ($$renderer3) => {
      $$renderer3.push(`Select a department`);
    });
    $$renderer2.push(`<!--[-->`);
    const each_array_1 = ensure_array_like(departments);
    for (let $$index_1 = 0, $$length = each_array_1.length; $$index_1 < $$length; $$index_1++) {
      let dept = each_array_1[$$index_1];
      $$renderer2.option({ value: dept }, ($$renderer3) => {
        $$renderer3.push(`${escape_html(dept)}`);
      });
    }
    $$renderer2.push(`<!--]-->`);
  });
  $$renderer.push(`</label> <label>Category `);
  $$renderer.select({ value: formData.category, required: true }, ($$renderer2) => {
    $$renderer2.option({ value: "", disabled: true, selected: true }, ($$renderer3) => {
      $$renderer3.push(`Select a category`);
    });
    $$renderer2.push(`<!--[-->`);
    const each_array_2 = ensure_array_like(categories);
    for (let $$index_2 = 0, $$length = each_array_2.length; $$index_2 < $$length; $$index_2++) {
      let category = each_array_2[$$index_2];
      $$renderer2.option({ value: category }, ($$renderer3) => {
        $$renderer3.push(`${escape_html(category)}`);
      });
    }
    $$renderer2.push(`<!--]-->`);
  });
  $$renderer.push(`</label> <label>Student level `);
  $$renderer.select({ value: formData.level, required: true }, ($$renderer2) => {
    $$renderer2.option({ value: "", disabled: true, selected: true }, ($$renderer3) => {
      $$renderer3.push(`Select a level`);
    });
    $$renderer2.push(`<!--[-->`);
    const each_array_3 = ensure_array_like(studentLevels);
    for (let $$index_3 = 0, $$length = each_array_3.length; $$index_3 < $$length; $$index_3++) {
      let level = each_array_3[$$index_3];
      $$renderer2.option({ value: level }, ($$renderer3) => {
        $$renderer3.push(`${escape_html(level)}`);
      });
    }
    $$renderer2.push(`<!--]-->`);
  });
  $$renderer.push(`</label> <button type="submit">Enter</button></form></main>`);
}
export {
  _page as default
};
