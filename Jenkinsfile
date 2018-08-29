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
	post {
    		failure {
       			mail to: 'alex.strole004@gmail.com',
             		subject: "Failed Pipeline: ${currentBuild.fullDisplayName}",
             		body: "Something is wrong with ${env.BUILD_URL}"
		}
    		success {
       			mail to: 'alex.strole004@gmail.com',
             		subject:"Succeeded! ${currentBuild.fullDisplayName}",
             		body: "Everything is good and great ${env.BUILD_URL}"
		}
	}
}
