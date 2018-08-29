pipeline {
	agent any
	stages {
		stage ('Build') {
			steps {
				sh "make"
				sh "echo Done"
			}
		}
	}
	post {
		success {
			sh "make fclean"
		}
	}
}
