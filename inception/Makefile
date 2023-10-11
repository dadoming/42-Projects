
all:
	sh ./srcs/requirements/tools/make_dir.sh
	docker-compose -f ./srcs/docker-compose.yml up -d --build

down:
	docker-compose -f ./srcs/docker-compose.yml down

clean: down
	sudo rm -rf ../../data/
	docker system prune -a

fclean:
	sudo rm -rf ../../data/
	docker stop $$(docker ps -qa)
	docker system prune --all --force --volumes
	docker network prune --force
	docker volume prune --force

re: fclean all

# clean_eval:
# docker stop $(docker ps -qa);
# docker rm $(docker ps -qa);
# docker rmi -f $(docker images -qa);
# docker volume rm $(docker volume ls -q);
# docker network rm $(docker network ls -q) 2>/dev/null

logs:
	@echo ">> MariaDB:\n"
	docker logs mariadb
	@echo "\n"
	@echo ">> Nginx:\n"
	docker logs nginx
	docker exec -it nginx cat /var/log/nginx/error.log
	@echo "\n"
	@echo ">> Wordpress:\n"
	docker logs wordpress
	@echo "\n"
	@echo ">> Website:\n"
	docker logs website
	@echo "\n"

.PHONY: all down re clean fclean logs 
