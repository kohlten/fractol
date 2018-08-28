Jenkinsfile (Declarative Pipeline)
pipline {
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
