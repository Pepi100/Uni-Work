		class Student {
		  
		  constructor(nume, prenume,grupa) {
			var p_nota=10;
			this.get_nota=function(){
			  return p_nota;
			}
			this.set_nota=function(n){p_nota=n}
			this.nume = nume;
			this.prenume = prenume;
			this.grupa = grupa;
		  }
		  //1
		  /*  va merge?
		  set nume(nm){
			this.nume=nm;
		  }
		  */
		  //2
		  
		  
		  set nr_grupa(gr){
			if(typeof gr === "number")
				this.grupa=gr;
			else
				this.grupa=0;
		  }
		  //3
		  set nume_prenume_grupa(vect_prop){
			this.nume = vect_prop[0];
			this.prenume = vect_prop[1];
			this.grupa = vect_prop[2];
		  }	
		  /*
		  get nume(){
			return this.nume;  
		  }*/
		  //4
		  get nr_grupa(){
			return "Grupa: "+this.grupa;  
		  }
		  get nume_prenume(){
			return this.nume+ " "+ this.prenume;  
		  }
		  
		  

		  
		  afis(){
			  document.write("<p>Student:<br>"+
			  "Nume: "+this.nume+"<br/>"+
			  "Prenume: "+this.prenume+"<br/>"+
			  "Grupa: "+this.grupa+"</p>"
			  );
		  }
		  //5
		  static afis_motto()
		  {
			  document.write(Student.motto);
		  }
		  
		  get motto_real() {
				return this.constructor.motto_real;
		  }
		  
		  afis_motto_real(){
			  document.write("<p>"+this.motto_real+"</p>");
		  }
		}
		Student.motto = "Imi place materia tehnici web!"
		Student.motto_real = "Vreau sa dorm"
		
		
		Student.prototype.tipa=function(){
			alert("Yaaaaaaaaay!");
		}
		
		class SefDeGrupa extends Student{
			afis(){
				super.afis();
				document.write("<p>Si este sef de grupa</p>");
			}
		}