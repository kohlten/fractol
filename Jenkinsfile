pipeline {
	agent any
	stages {
		stage ('Build') {
			steps {
				sh "make"
				sh "echo Done"
				sh "make fclean"
			}
		}
	}
}
